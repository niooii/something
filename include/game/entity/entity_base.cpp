//
// Created by niooi on 2/17/24.
//

#include "entity_base.h"

namespace Entity
{
    // Utility
    float EntityBase::apply_defense_to_dmg(float incoming_dmg) const
    {
        return (1.f - defense/100.f) * incoming_dmg;
    }

    // Default virtual methods
    void EntityBase::OnDealDmg(float original_dmg, float true_dmg_taken, EntityBase *dmged_entity)
    {

    }


    float EntityBase::ProcessIncomingDmg(float original_dmg, EntityBase *dmg_dealer)
    {
        return apply_defense_to_dmg(original_dmg);
    }



    // Other
    void EntityBase::TakeDamageFrom(EntityBase *dmg_dealer)
    {
        if (!this->can_take_damage)
        {
            return;
        }
        float original_dmg = dmg_dealer->GetOutgoingDamage();
        // will probably change later
        if (original_dmg == 0)
        {
            return;
        }
        float true_dmg = ProcessIncomingDmg(original_dmg, dmg_dealer);
        this->health -= true_dmg;
        this->OnTakeDmg(original_dmg, true_dmg, dmg_dealer);
        dmg_dealer->OnDealDmg(original_dmg, true_dmg, this);
    }
}
