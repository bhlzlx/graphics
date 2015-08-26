#ifndef UICOMMON_H
#define UICOMMON_H

namespace UI
{

    struct UISize
    {
        UISize(float width,float height)
        {
            this->dx = width;
            this->dy = height;
        }
        float dx;
        float dy;
    };

}

#endif // UICOMMON_H
