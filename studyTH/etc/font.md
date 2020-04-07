## Font Rendering 짤막 스터디

참고
- https://learnopengl.com/In-Practice/Text-Rendering
- https://doc.qt.io/qt-5/qt-embedded-fonts.html

폰트를 만들어 내는 방식은 몇가지 있다.

1. 사용가능한 글자(Glyph)들을 한데 모아 텍스처로 만들어내는 방식
  - 사용할 땐 필요한 글자를 잘라서 배치한다.
  - scalability 등 단점이 있다.
  - 예: http://www.codehead.co.uk/cbfg/

2. FreeType Engine
  - 각 Glyph가 바로 image 형태로 존재하는 것이 아니고 math equation으로 존재함
  - 로드 후 pixel 사이즈 등을 입력하여 원하는 글자로 바꾼다.
  - 퀄리티가 저하되지 않는다.

#include <ft2build.h>
#include FT_FREETYPE_H

FT_Library ft;
if (FT_Init_FreeType(&ft))
    std::cout << "ERROR::FREETYPE: Could not init FreeType Library" << std::endl;

FT_Face face;
if (FT_New_Face(ft, "fonts/arial.ttf", 0, &face))
    std::cout << "ERROR::FREETYPE: Failed to load font" << std::endl;

FT_Set_Pixel_Sizes(face, 0, 48);

if (FT_Load_Char(face, 'X', FT_LOAD_RENDER))
    std::cout << "ERROR::FREETYTPE: Failed to load Glyph" << std::endl;

By setting FT_LOAD_RENDER as one of the loading flags, we tell FreeType to create
an 8-bit grayscale bitmap image for us that we can access via face->glyph->bitmap.

- to be continued
