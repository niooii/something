//
// Created by niooi on 2/17/24.
//

#ifndef HORSE_ENTITY_BASE_H
#define HORSE_ENTITY_BASE_H
#include <optional>

#include "app.h"
#include "entity_types.h"
#include "geometry/rect.h"

namespace Entity
{
    class EntityBase
    {
    protected:
        // Attributes
        EntityType entity_type;
        float damage{1};
        float health{100};
        float defense{20};
        std::optional<Geometry::Rect> hitbox{};
        bool can_take_damage{true};
        bool is_interactable{false};

        // Utility
        float apply_defense_to_dmg(float incoming_dmg) const;

        // Callbacks

        // called after damage is dealt to the target
        virtual void OnDealDmg(float original_dmg, float true_dmg_taken, EntityBase* dmged_entity, App* app);

        // called before damage is applied
        // returns any changes to the incoming damage,
        // eg defense or buff modifiers etc something something
        // if it returns 0, damage is not applied.
        virtual float ProcessIncomingDmg(float original_dmg, EntityBase* dmg_dealer, App* app);

        // called after damage is applied
        // is NOT called when damage == 0.
        virtual void OnTakeDmg(float original_dmg, float true_dmg, EntityBase* dmg_dealer, App* app);

        // called when the entity has can_take_damage = false,
        // but has tried to take damage.
        virtual void OnTakeDmgFailed(float original_dmg, float true_dmg, EntityBase* dmg_dealer, App* app);

        // on so-called "interact" event
        virtual void OnInteract(EntityBase* interactor, App* app);

    public:
        // Accessors
        inline float GetOutgoingDamage() const { return damage; };

        inline float GetHealth() const { return health; }

        inline EntityType GetEntityType() const { return entity_type; };

        inline std::optional<Geometry::Rect> GetHitbox() const { return hitbox; }

        inline bool IsInteractable() const { return is_interactable; }

        // Other
        void TakeDamageFrom(EntityBase* dmg_dealer, App* app);
    };
}

#endif //HORSE_ENTITY_BASE_H
