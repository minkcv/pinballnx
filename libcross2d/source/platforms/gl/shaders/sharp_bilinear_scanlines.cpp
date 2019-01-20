//
// Created by cpasjuste on 15/09/18.
//

// texture
const char *sharp_bilinear_scanlines_v = R"text(
    #version 330 core

    #pragma parameter SCANLINE_BASE_BRIGHTNESS "Scanline Base Brightness" 0.60 0.0 1.0 0.01
    #pragma parameter SCANLINE_HORIZONTAL_MODULATION "Scanline Horizontal Modulation" 0.0 0.0 2.00 0.01
    #pragma parameter SCANLINE_VERTICAL_MODULATION "Scanline Vertical Modulation" 0.75 0.0 2.0 0.01

    #define pi 3.141592654

    #if __VERSION__ >= 130
    #define COMPAT_VARYING out
    #define COMPAT_ATTRIBUTE in
    #define COMPAT_TEXTURE texture
    #else
    #define COMPAT_VARYING varying
    #define COMPAT_ATTRIBUTE attribute
    #define COMPAT_TEXTURE texture2D
    #endif

    #ifdef GL_ES
    #define COMPAT_PRECISION mediump
    #else
    #define COMPAT_PRECISION
    #endif

    // CROSS2D
    //COMPAT_ATTRIBUTE vec4 VertexCoord;
    //COMPAT_ATTRIBUTE vec4 COLOR;
    //COMPAT_ATTRIBUTE vec4 TexCoord;
    layout (location = 0) in vec4 VertexCoord;
    layout (location = 1) in vec4 COLOR;
    layout (location = 2) in vec4 TexCoord;
    uniform mat4 modelViewMatrix;
    uniform mat4 projectionMatrix;
    uniform mat4 textureMatrix;
    // CROSS2D
    COMPAT_VARYING vec4 COL0;
    COMPAT_VARYING vec4 TEX0;
    COMPAT_VARYING vec2 omega;

    uniform mat4 MVPMatrix;
    uniform COMPAT_PRECISION int FrameDirection;
    uniform COMPAT_PRECISION int FrameCount;
    uniform COMPAT_PRECISION vec2 OutputSize;
    uniform COMPAT_PRECISION vec2 TextureSize;
    uniform COMPAT_PRECISION vec2 InputSize;

    // vertex compatibility #defines
    #define vTexCoord TEX0.xy
    #define SourceSize vec4(TextureSize, 1.0 / TextureSize) //either TextureSize or InputSize
    #define outsize vec4(OutputSize, 1.0 / OutputSize)

    COMPAT_VARYING vec2 precalc_texel;
    COMPAT_VARYING vec2 precalc_scale;

    void main()
    {
        // CROSS2D
        // gl_Position = MVPMatrix * VertexCoord;
        gl_Position = projectionMatrix * (modelViewMatrix * vec4(VertexCoord.x, VertexCoord.y, 0.0, 1.0));
        COL0 = COLOR;
        // CROSS2D
        // TEX0.xy = TexCoord.xy;
        TEX0 = textureMatrix * vec4(VertexCoord.x, VertexCoord.y, 0.0, 1.0);
        omega = vec2(pi * OutputSize.x, 2.0 * pi * TextureSize.y);

        precalc_texel = vTexCoord * SourceSize.xy;
        precalc_scale = max(floor(outsize.xy / InputSize.xy), vec2(1.0, 1.0));
    }

)text";

const char *sharp_bilinear_scanlines_f = R"text(
    #version 330

    #pragma parameter SCANLINE_BASE_BRIGHTNESS "Scanline Base Brightness" 0.60 0.0 1.0 0.01
    #pragma parameter SCANLINE_HORIZONTAL_MODULATION "Scanline Horizontal Modulation" 0.0 0.0 2.00 0.01
    #pragma parameter SCANLINE_VERTICAL_MODULATION "Scanline Vertical Modulation" 0.75 0.0 2.0 0.01

    #define pi 3.141592654

    #if __VERSION__ >= 130
    #define COMPAT_VARYING in
    #define COMPAT_TEXTURE texture
    out vec4 FragColor;
    #else
    #define COMPAT_VARYING varying
    #define FragColor gl_FragColor
    #define COMPAT_TEXTURE texture2D
    #endif

    #ifdef GL_ES
    #ifdef GL_FRAGMENT_PRECISION_HIGH
    precision highp float;
    #else
    precision mediump float;
    #endif
    #define COMPAT_PRECISION mediump
    #else
    #define COMPAT_PRECISION
    #endif

    uniform COMPAT_PRECISION int FrameDirection;
    uniform COMPAT_PRECISION int FrameCount;
    uniform COMPAT_PRECISION vec2 OutputSize;
    uniform COMPAT_PRECISION vec2 TextureSize;
    uniform COMPAT_PRECISION vec2 InputSize;
    uniform sampler2D Texture;
    COMPAT_VARYING vec4 TEX0;
    COMPAT_VARYING vec2 omega;

    // fragment compatibility #defines
    #define Source Texture
    #define vTexCoord TEX0.xy

    #define SourceSize vec4(TextureSize, 1.0 / TextureSize) //either TextureSize or InputSize
    #define outsize vec4(OutputSize, 1.0 / OutputSize)

    #ifdef PARAMETER_UNIFORM
    // All parameter floats need to have COMPAT_PRECISION in front of them
    uniform COMPAT_PRECISION float SCANLINE_BASE_BRIGHTNESS;
    uniform COMPAT_PRECISION float SCANLINE_HORIZONTAL_MODULATION;
    uniform COMPAT_PRECISION float SCANLINE_VERTICAL_MODULATION;
    #else
    #define SCANLINE_BASE_BRIGHTNESS 0.60
    #define SCANLINE_HORIZONTAL_MODULATION 0.0
    #define SCANLINE_VERTICAL_MODULATION 0.75
    #endif

    COMPAT_VARYING vec2 precalc_texel;
    COMPAT_VARYING vec2 precalc_scale;

    void main()
    {
       vec2 texel = precalc_texel;
       vec2 scale = precalc_scale;

       vec2 texel_floored = floor(texel);
       vec2 s = fract(texel);
       vec2 region_range = 0.5 - 0.5 / scale;

       // Figure out where in the texel to sample to get correct pre-scaled bilinear.
       // Uses the hardware bilinear interpolator to avoid having to sample 4 times manually.

       vec2 center_dist = s - 0.5;
       vec2 f = (center_dist - clamp(center_dist, -region_range, region_range)) * scale + 0.5;

       vec2 mod_texel = texel_floored + f;

       vec3 res = COMPAT_TEXTURE(Source, mod_texel / SourceSize.xy).xyz;

       // thick scanlines (thickness pre-calculated in vertex shader based on source resolution)
       vec2 sine_comp = vec2(SCANLINE_HORIZONTAL_MODULATION, SCANLINE_VERTICAL_MODULATION);

       vec3 scanline = res * (SCANLINE_BASE_BRIGHTNESS + dot(sine_comp * sin(vTexCoord * omega), vec2(1.0, 1.0)));
       FragColor = vec4(scanline.rgb, 1.0);
    }

)text";
