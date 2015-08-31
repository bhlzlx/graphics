#include <gl/glew.h>
#include "BufferOGL.h"

namespace Graphics
{
    VertexBuffer::VertexBuffer()
    {
        
    }
    
    VertexBuffer::VertexBuffer(const VertexBuffer&)
    {
        
    }
    
    VertexBuffer * VertexBuffer::CreateBuffer(const void * _ptr,GLsizei _nSize)
    {
        VertexBuffer * pBuffer = new VertexBuffer();
        
        glGenBuffers(1,&pBuffer->m_buffer);
        glBindBuffer(GL_ARRAY_BUFFER,pBuffer->m_buffer);
        glBufferData(GL_ARRAY_BUFFER,_nSize,_ptr,GL_STATIC_DRAW);
        glBindBuffer(GL_ARRAY_BUFFER,0);
        
        pBuffer->m_bufferSize = _nSize;
        pBuffer->m_bDynamic = GL_FALSE;
        
        return pBuffer;
    }
    
    VertexBuffer * VertexBuffer::CreateBufferDyn( GLsizei _nSize)
    {
        VertexBuffer * pBuffer = new VertexBuffer();
        
        glGenBuffers(1,&pBuffer->m_buffer);
        glBindBuffer(GL_ARRAY_BUFFER,pBuffer->m_buffer);
        glBufferData(GL_ARRAY_BUFFER,_nSize,NULL,GL_STATIC_DRAW);
        glBindBuffer(GL_ARRAY_BUFFER,0);
        
        pBuffer->m_bufferSize = _nSize;
        pBuffer->m_bDynamic = GL_TRUE;
        
        return pBuffer;
    }
    
    GLboolean VertexBuffer::SetSubData(intptr_t offset,const void * _ptr,size_t _nSize)
    {
        glBindBuffer(GL_ARRAY_BUFFER,m_buffer);
        if(offset + _nSize > (GLuint)this->m_bufferSize)
            return GL_FALSE;
        glBufferSubData(GL_ARRAY_BUFFER,offset,_nSize,_ptr);
        return GL_TRUE;
    }
    
    void VertexBuffer::Release()
    {
        glDeleteBuffers(1,&m_buffer);
        delete this;
    }
    
    IndexBuffer * IndexBuffer::CreateBuffer(void * _ptr,GLsizei _nSize)
    {
        IndexBuffer * pBuffer = new IndexBuffer();
        glGenBuffers(1,&pBuffer->m_buffer);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,pBuffer->m_buffer);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER,_nSize,_ptr,GL_STATIC_DRAW);
        
    }
    
    void IndexBuffer::Release()
    {
        glDeleteBuffers(1,&m_buffer);
        delete this;
    }
    
    VertexArray::VertexArray()
    {
        glGenVertexArrays(1,&m_vertexArray);
        m_bIndexed = false;
    }
    
    void VertexArray::SetIndexBuffer(VertexBuffer * _pIndexBuffer)
    {
        glBindVertexArray(this->m_vertexArray);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,_pIndexBuffer->m_buffer);
        m_bIndexed = true;
    }
    
    void VertexArray::SetVertexBuffer(
                                        GLuint _vbo_index, 
                                        VertexBuffer * _pBuffer,
                                        GLuint _nElement,
                                        GLuint _nStride,
                                        GLint _nOffset,
										GLenum _nType)
    {
        glBindVertexArray(this->m_vertexArray);
        glBindBuffer(GL_ARRAY_BUFFER,_pBuffer->m_buffer);
        glVertexAttribPointer(_vbo_index,_nElement,_nType,GL_FALSE,_nStride,(void*)_nOffset);
        glEnableVertexAttribArray(_vbo_index);
    }    
	
	void VertexArray::SetVertexBufferI(
                                        GLuint _vbo_index, 
                                        VertexBuffer * _pBuffer,
                                        GLuint _nElement,
                                        GLuint _nStride,
                                        GLint _nOffset,
										GLenum _nType)
    {
        glBindVertexArray(this->m_vertexArray);
        glBindBuffer(GL_ARRAY_BUFFER,_pBuffer->m_buffer);
        glVertexAttribIPointer(_vbo_index,_nElement,_nType,_nStride,(void*)_nOffset);
        glEnableVertexAttribArray(_vbo_index);
    }
    
    void VertexArray::Release()
    {
        glDeleteVertexArrays(1,&m_vertexArray);
        delete this;
    }
    
    VertexArray * VertexArray::CreateVertexArray()
    {
        return new VertexArray;
    }
    
    void VertexArray::Bind()
    {
        glBindVertexArray(this->m_vertexArray);
    }
    
    void VertexArray::Draw( int _nVertices )
    {
        if(m_bIndexed)
        {
            glDrawElements(GL_TRIANGLES,_nVertices,GL_UNSIGNED_INT,NULL);
        }
        else
        {            
            glDrawArrays(GL_TRIANGLES,0,_nVertices);
        }
    }
};
