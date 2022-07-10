#include <list>
#include <algorithm>
#include <iterator>


class Object {
 public:
    bool modified() {
        // TODO: object was added
        // TODO: object was removed
        // TODO: object was modified
            // TODO: transform changed
            // TODO: texture changed
            // TODO: visibility status changed
    }


};

using GLdouble = double;

std::list<Object> filterOccluded(std::list<Object> objects)
{}

class Frustum {
 public:
    GLdouble left,GLdouble right,
 	GLdouble bottom, GLdouble top, GLdouble nearVal, GLdouble farVal;

    Frusum(Scene& scene);

    const std::list<Object>& visibleObjects();
    const std::list<Object>& redrawRequiredObjects();

 private:

    bool contains(const Object& object) const noexcept;
    std::list<Object> cull(const Object>& object) const noexcept;
    
    std::list<Object> contains(const std::list<Object>& objects) const noexcept;
    std::list<Object> cull(const std::list<Object>& objects) const noexcept {
        std::list<Object> visibleObjects = contains(objects); // Frustum Culling
        return filterOccluded(visibleObjects);
    }

    bool changed() noexcept {
        const bool cameraChanged { true };   // TODO

        if (cameraChanged) {
            // TODO: mark all objects as dirty
            _visibleObjects = cull(_objects);
            return;
        } 
    
        std::list<Object> changedObjects { findModifiedObjects() };
        if (!changedObjects.empty()) {
            std::list<Object> affectedObjects { findAffectedObjects(changedObjects) };
            std::list<Object> affectedObjects { contains(affectedObjects) };
            _visibleObjects = cull(affectedObjects);
        }
    }

    std::list<Object> findModifiedObjects() const {
        std::list<Object> modifedObjects;
        std::copy_if(_objects.begin(), _objects.end(),
                     std::back_inserter(modifedObjects), [] (auto &object) { return object->modified(); });
        return modifedObjects;
    }

    std::list<Object> findAffectedObjects();

    std::list<Object> _objects;
    mutable std::list<Object> _visibleObjects;
///////////////////////////////////////////////////////////

};