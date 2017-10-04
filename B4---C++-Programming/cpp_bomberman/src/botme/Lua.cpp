//
// Created by Fabien Martinez on 21/05/15.
//

#include "Error.hpp"
#include "Lua.hh"

Lua::Lua(const std::string& filename, int width, int height) {
    this->m_L = luaL_newstate();
    if (luaL_loadfile(this->m_L, filename.c_str()) || lua_pcall(this->m_L, 0, 0, 0)) {
        std::cerr << "Error: [" << filename << "]: unable to load lua file" << std::endl;
        this->m_L = 0;
	throw ErrorBomberman("Unable to load lua file", "LUA");
    }
    luaL_openlibs(this->m_L);
    this->m_width = width;
    this->m_height = height;
}

Lua::~Lua() {
    if (this->m_L)
        lua_close(this->m_L);
}

int     Lua::getPosition(const char *map, int x, int y) {
    int direction;
    lua_getglobal(this->m_L, "execute");
    lua_pushstring(this->m_L, map);
    lua_pushnumber(this->m_L, x);
    lua_pushnumber(this->m_L, y);
    lua_pushnumber(this->m_L, this->m_width);
    lua_pushnumber(this->m_L, this->m_height);
    if (lua_pcall(this->m_L, 5, 1, 0) != 0) {
      std::cerr << "Error: Unable to use pcall: " << lua_tostring(this->m_L, -1) << std::endl;
        lua_close(this->m_L);
        this->m_L = 0;
        return (-1);
    }
    direction = lua_tonumber(this->m_L, -1);
    lua_pop(this->m_L, 1);
    return direction;
}
