#ifndef LE2_MAINHOOKS_H
#define LE2_MAINHOOKS_H

namespace lost
{

void leStartup();
void leUpdate();
void leShutdown();
void leWindowResize(float w, float h);

}

#endif