#ifndef INFOSCREEN_H_
#define INFOSCREEN_H_

#include "cross2d/c2d.h"
#include <stdlib.h>

using namespace c2d;
using namespace std;

class InfoScreen {
    public:
        InfoScreen(C2DRenderer* renderer);
        void show();
        void hide();
    private:
        vector<C2DText*> m_textLines;
        C2DRectangle* m_shape;
};
#endif