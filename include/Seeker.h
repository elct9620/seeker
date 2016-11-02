// Copyright 2016 Zheng Xian Qiu

#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

// Utils
#include "Utils.h"
#include "StringUtils.h"

// Interfaces
#include "IScript.h"

// Core
#include "Event.h"
#include "EventManager.h"
#include "Errors.h"
#include "Logger.h"
#include "Resource.h"
#include "Window.h"
#include "Renderer.h"
#include "Config.h"
#include "Instance.h"
#include "Framework.h"

// UI
#include "UI/Event.h"
#include "UI/Widget.h"
#include "UI/TextWidget.h"

// Game - Assets
#include "Texture.h"
#include "Sprite.h"
#include "Font.h"

// Game - Croe
#include "GameState.h"
#include "GameObject.h"
#include "Actor.h"
#include "Scene.h"

// Game Script
#include "Ruby.h"

// Script Engine
#include "Ruby/Engine.h"
#include "Ruby/Config.h"
#include "Ruby/Game.h"
#include "Ruby/RubyObject.h"
#include "Ruby/Scene.h"
#include "Ruby/Actor.h"
#include "Ruby/UI/TextWidget.h"
