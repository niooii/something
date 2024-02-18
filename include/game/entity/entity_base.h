//
// Created by niooi on 2/17/24.
//

#ifndef HORSE_ENTITY_BASE_H
#define HORSE_ENTITY_BASE_H
#include <optional>

#include "entity_types.h"
#include "game/geometry/rect.h"

namespace Entity
{
    class EntityBase
    {
    private:

    protected:
        // Attributes
        EntityType entity_type;
        float damage{1};
        float health{100};
        float defense{20};
        std::optional<Geometry::Rect> hitbox{};
        bool can_take_damage{true};

        // Utility
        float apply_defense_to_dmg(float incoming_dmg) const;

        // Callbacks

        // called after damage is dealt to the target
        virtual void OnDealDmg(float original_dmg, float true_dmg_taken, EntityBase* dmged_entity);

        // called before damage is applied
        // returns any changes to the incoming damage,
        // eg defense or buff modifiers etc something something
        // if it returns 0, damage is not applied.
        virtual float ProcessIncomingDmg(float original_dmg, EntityBase *dmg_dealer);

        // called after damage is applied
        // is NOT called when damage == 0.
        virtual void OnTakeDmg(float original_dmg, float true_dmg, EntityBase *dmg_dealer);

        // called when the entity has can_take_damage = false,
        // but has tried to take damage.
        virtual void OnTakeDmgFailed(float original_dmg, float true_dmg, EntityBase *dmg_dealer);

    public:
        // Accessors
        inline float GetOutgoingDamage()
        {
            return damage;
        };

        inline EntityType GetEntityType()
        {
            return entity_type;
        };

        inline std::optional<Geometry::Rect> GetHitbox()
        {
            return hitbox;
        }

        // Other
        void TakeDamageFrom(EntityBase *dmg_dealer);
    };
}

#endif //HORSE_ENTITY_BASE_H
