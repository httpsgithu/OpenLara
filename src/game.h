#ifndef H_GAME_TR
#define H_GAME_TR

//#define FREE_CAMERA

#include "core.h"
#include "format.h"
#include "level.h"

namespace Game {
    Level *level;

    void init() {
        Core::init();
        //level = new Level("LEVEL2.PHD", false, false);
        //level = new Level("GYM.PHD", false, true);
        //level = new Level("LEVEL3A.PHD", false, false);
        level = new Level("LEVEL2.PSX", false, false);

        #ifndef __EMSCRIPTEN__    
            //Sound::play(Sound::openWAD("05_Lara's_Themes.wav"), 1, 1, 0);
            Sound::play(new Stream("05.ogg"), vec3(0.0f), 1, 1, Sound::Flags::LOOP);
            //Sound::play(new Stream("03.mp3"), 1, 1, 0);
        #endif
    }

    void free() {
        delete level;

        Core::free();
    }

    void update() {
        float dt = Core::deltaTime;
        if (Input::down[ikR]) // slow motion (for animation debugging)
            Core::deltaTime /= 10.0f;
        if (Input::down[ikT])
            Core::deltaTime *= 10.0f;

        level->update();

        Core::deltaTime = dt;
    }

    void render() {
        level->render();
    }
}

#endif