#include "device.h"
#include <png.h>
#include <pngstruct.h>
#include <pnginfo.h>
#include <memory.h>
#include <assert.h>

namespace Graphics
{    
    static void IBufferPNGReadFunc(png_structp s_ptr,png_bytep data,png_size_t size)
    {
        ow::IBuffer * pBuff = (ow::IBuffer *)png_get_io_ptr(s_ptr);
        pBuff->Read((int8_t*)data,size);
    }
    
    void Image::Release()
    {
        delete[] this->pData;
        delete this;
    }
    
    Image * Image::ImageFromPng(ow::IBuffer * _pBuffer)
    {
        if(!_pBuffer)
            return NULL;
        png_structp s_ptr = png_create_read_struct(PNG_LIBPNG_VER_STRING,0,0,0);
        png_infop   i_ptr = png_create_info_struct(s_ptr);
        setjmp(png_jmpbuf(s_ptr));
        png_set_read_fn(s_ptr,_pBuffer,IBufferPNGReadFunc);
        png_read_png(s_ptr,i_ptr, PNG_TRANSFORM_EXPAND , 0);
        
        int color_type = i_ptr->color_type;
        //int pixel_depth = i_ptr->pixel_depth;        
        if(i_ptr->bit_depth!=8)
            return NULL;
        if(!i_ptr->channels)
            return NULL;

        Image * pImage = new Image();
        pImage->nHeight = i_ptr->height;
        pImage->nWidth = i_ptr->width;
        // 强制4个字节，32bit~
        unsigned long buff_size = pImage->nHeight * pImage->nWidth * 4;
        png_bytep* row_pointers = png_get_rows(s_ptr,i_ptr);
        pImage->pData = new unsigned char[buff_size];
        if(color_type == PNG_COLOR_TYPE_RGBA)
        {
            for(int i = 0;i<pImage->nHeight;i++)
            {
                memcpy(pImage->pData+(pImage->nWidth*4*i),
                       row_pointers[i],
                       pImage->nWidth*4
                );
            }
        }
        else if(color_type == PNG_COLOR_TYPE_RGB)
        {
            for(int i = 0;i<pImage->nHeight;i++)
            {
                for(int j = 0;j<pImage->nWidth;j++)
                {
                    unsigned char * pColors = pImage->pData + i*pImage->nWidth*4 + 4 * j;
                    unsigned char * pIn = (unsigned char *)row_pointers[i] + 3 * j;
                    pColors[0] = pIn[0];
                    pColors[1] = pIn[1];
                    pColors[2] = pIn[2];
                    pColors[3] = 0xff;
                }
            }
        }
        else
        {
            return NULL;
        }
        png_destroy_read_struct(&s_ptr, &i_ptr, 0);
        return pImage;
    }
    
}