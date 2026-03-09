#include "extra.h"
#include "main.h"
#include <3ds.h>
#include <citro2d.h>

void
drawStick (const u32 &kDown, const circlePosition &pos)
{
  u32 white = C2D_Color32 (0xFF, 0xFF, 0xFF, 0xFF);

  if (kDown & KEY_B)
    mainMenuSet ();

  m_useColor (0xFF, 0xFF, 0xFF);
  m_circle (165, 85, 70);
  m_useColor (0x35, 0x3E, 0x4A);
  m_circle (167, 87, 66);

  // 400*240
  C2D_DrawLine (180 + pos.dx / 5, 120 + pos.dy / -5, white, 220 + pos.dx / 5,
                120 + pos.dy / -5, white, 2, 0);
  C2D_DrawLine (200 + pos.dx / 5, 100 + pos.dy / -5, white, 200 + pos.dx / 5,
                140 + pos.dy / -5, white, 2, 0);
}

void
drawLStick (int, int)
{
  hidScanInput ();
  u32 kDown = hidKeysDown ();
  circlePosition pos;
  hidCircleRead (&pos);
  drawStick (kDown, pos);
}

void
drawCStick ()
{
  hidScanInput ();
  u32 kDown = hidKeysDown ();
  circlePosition pos;
  hidCstickRead (&pos);
  drawStick (kDown, pos);
}
