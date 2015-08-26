#ifndef __BUFFER_OGL__
#define __BUFFER_OGL__

#include <gl/gl.h>
#include <cstdint>

namespace Graphics
{

    struct VertexBuffer
    {
        GLuint      m_buffer;
        GLsizei     m_bufferSize;
        GLboolean   m_bDynamic;
        
        static VertexBuffer * CreateBuffer(const void * _ptr,GLsizei _nSize);
        static VertexBuffer * CreateBufferDyn( GLsizei _nSize);
        
        GLboolean SetSubData(intptr_t offset,const void * _ptr,size_t _nSize);
        void Release();
    private:
        VertexBuffer();
        VertexBuffer( const VertexBuffer &);
    };
    
    struct IndexBuffer
    {
        GLuint  m_buffer;
        GLsizei m_bufferSize;
        
        static IndexBuffer * CreateBuffer(void * _ptr,GLsizei _nSize);
        void Release();
    };
    
    struct VertexArray
    {
        GLuint m_vertexArray;
        
        bool   m_bIndexed;
        
        VertexArray();
        
        static VertexArray * CreateVertexArray();
        
        void SetIndexBuffer(VertexBuffer * _pIndexBuffer);
        void SetVertexBuffer(
                            GLuint _vbo_index, 
                            VertexBuffer * _pBuffer,
                            GLuint _nElement,
                            GLuint _nStride,
                            GLint _nOffset,
							GLenum _nType = GL_FLOAT
							);
		void SetVertexBufferI(
									GLuint _vbo_index, 
									VertexBuffer * _pBuffer,
									GLuint _nElement,
									GLuint _nStride,
									GLint _nOffset,
									GLenum _nType);
        void Bind();
        void Draw( int _nVertices);
        void Release();
    };
}

#endif // __BUFFER_OGL__
