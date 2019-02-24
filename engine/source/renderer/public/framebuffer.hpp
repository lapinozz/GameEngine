#ifndef ENGINE_RENDERER_FRAMEBUFFER_HPP_INCLUDE
#define ENGINE_RENDERER_FRAMEBUFFER_HPP_INCLUDE

#include "enum_flag.hpp"
#include <cstdint>

namespace renderer {
    class Framebuffer {
    public:
        enum class Draw_Mode {
            static_draw,
            streamed_draw,
            dynamic_draw,
        };

        enum class Bind_Mode {
            read,
            draw,
            read_draw,
        };

        enum class Buffer_Type {
            renderbuffer,
            texture,
        };

        enum class Attachment {
            color,
            depth_stencil,
            depth,
            stencil,
        };

        enum Buffer_Mask : uint32_t {
            color = 1 << 0,
            depth = 1 << 1,
            stencil = 1 << 2,
        };

        struct Construct_Info {
            uint32_t width = 0;
            uint32_t height = 0;
            uint32_t samples = 0;
            Attachment depth_buffer_attachment = Attachment::depth;
            Attachment stencil_buffer_attachment = Attachment::stencil;
            Buffer_Type depth_buffer_type = Buffer_Type::renderbuffer;
            Buffer_Type stencil_buffer_type = Buffer_Type::renderbuffer;
            bool color_buffer = true;
            bool depth_buffer = false;
            bool stencil_buffer = false;
            bool multisampled = false;
        };

        static void bind(Framebuffer&, Bind_Mode = Bind_Mode::read_draw);
        static void bind_default(Bind_Mode = Bind_Mode::read_draw);

        Framebuffer(Construct_Info const&);
        Framebuffer(Framebuffer&&) noexcept;
        Framebuffer& operator=(Framebuffer&&) noexcept;
        ~Framebuffer();

        Framebuffer() = delete;
        Framebuffer(Framebuffer const&) = delete;
        Framebuffer& operator=(Framebuffer const&) = delete;

        void clear();
        void blit(Framebuffer&, Buffer_Mask);
        uint32_t get_color_texture() const;
        uint32_t get_depth_texture() const;

    private:
        Construct_Info info;
        uint32_t framebuffer = 0;
        uint32_t depth_buffer = 0;
        uint32_t stencil_buffer = 0;
        uint32_t color_buffer = 0;
    };
} // namespace renderer

#endif // !ENGINE_RENDERER_FRAMEBUFFER_HPP_INCLUDE
