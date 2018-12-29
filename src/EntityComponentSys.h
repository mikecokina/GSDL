//
// Created by mike on 28.12.2018.
//

#ifndef GSDL_ENTITYCOMPONENTSYS_H
#define GSDL_ENTITYCOMPONENTSYS_H


#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <bitset>
#include <array>

// class def
class Component;
class Entity;

// const def
constexpr std::size_t maxComponents = 32;

// type def
using ComponentIDType = std::size_t;
using ComponentBitSetType = std::bitset<maxComponents>;
using ComponentArrayType = std::array<Component*, maxComponents>;


inline ComponentIDType getComponentID() {
    static ComponentIDType lastID = 0;
    return lastID++;
}

template <typename T> inline ComponentIDType getComponentGivenTypeID() noexcept {
    static ComponentIDType typeID = getComponentID();
    return typeID;
}

class Component {
public:
    Entity* entity;

    virtual void init() {}
    virtual void update() {}
    virtual void draw() {}
    virtual ~Component() {}
};

class Entity {

private:
    bool active = true;
    std::vector<std::unique_ptr<Component>> components;

    ComponentArrayType componentArray;
    ComponentBitSetType componentBitSet;

public:
    void update() {
        for (auto &c : components) c->update();
        for (auto &c : components) c->draw();
    }

    void draw() {}
    bool isActive() { return active; }
    void destroy() { active = false; }

    template <typename T> bool hasComponent() const {
        return componentBitSet[getComponentGivenTypeID<T>()];
    }

    template <typename T, typename... Ts> T &addComponent(Ts&&... args) {
        T *comp(new T(std::forward<Ts>(args)...));
        comp->entity = this;
        std::unique_ptr<Component> uPtr{ comp };
        components.emplace_back(std::move(uPtr));

        componentArray[getComponentGivenTypeID<T>()] = comp;
        componentBitSet[getComponentGivenTypeID<T>()] = true;

        comp->init();
        return *comp;
    }

    template<typename T> T& getComponent() const {
        auto ptr(componentArray[getComponentGivenTypeID<T>()]);
        return *static_cast<T*>(ptr);
    }
};

class Manager {
private:
    std::vector<std::unique_ptr<Entity>> entities;
public:
    void update() {
        for (auto& e : entities) {
            e->update();
        }
    }

    void draw() {
        for (auto& e : entities) {
            e->draw();
        }
    }

    void refresh() {

        entities.erase(std::remove_if(
                std::begin(entities),
                std::end(entities),
                [](const std::unique_ptr<Entity> &mEntity)
                {
                    return !mEntity->isActive();
                }),
                        std::end(entities));
    }

    Entity& addEntity() {
        auto * e = new Entity();
        std::unique_ptr<Entity> uPtr{ e };
        entities.emplace_back(std::move(uPtr));
        return * e;
    }
};


#endif //GSDL_ENTITYCOMPONENTSYS_H
