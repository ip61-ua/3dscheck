#include "extra.h"
#include <3ds.h>
#include <citro2d.h>

#define checkButtonsExpand(keys, key, x1, y1, x2, y2)                         \
  {                                                                           \
    (keys & key) ? m_useColor (0x00, 0xFF, 0x00)                              \
                 : m_useColor (0xFF, 0x00, 0x00);                             \
    m_rect (x1, y1, x2, y2);                                                  \
  }

void
checkButtons (bool n3ds = false)
{
  hidScanInput ();
  u32 keys = hidKeysHeld ();

  checkButtonsExpand (keys, KEY_A, 325, 110, 355, 130);
  checkButtonsExpand (keys, KEY_Y, 265, 110, 295, 130);
  checkButtonsExpand (keys, KEY_X, 295, 90, 325, 110);
  checkButtonsExpand (keys, KEY_B, 295, 130, 325, 150);

  checkButtonsExpand (keys, KEY_DRIGHT, 105, 110, 135, 130);
  checkButtonsExpand (keys, KEY_DLEFT, 45, 110, 75, 130);
  checkButtonsExpand (keys, KEY_DUP, 75, 90, 105, 110);
  checkButtonsExpand (keys, KEY_DDOWN, 75, 130, 105, 150);

  checkButtonsExpand (keys, KEY_SELECT, 100, 190, 160, 210);
  checkButtonsExpand (keys, KEY_START, 240, 190, 300, 210);

  checkButtonsExpand (keys, KEY_L, 50, 50, 110, 70);
  checkButtonsExpand (keys, KEY_R, 290, 50, 350, 70);

  if (n3ds)
    {
      checkButtonsExpand (keys, KEY_ZL, 120, 50, 150, 70);
      checkButtonsExpand (keys, KEY_ZR, 250, 50, 280, 70);
    }
}
