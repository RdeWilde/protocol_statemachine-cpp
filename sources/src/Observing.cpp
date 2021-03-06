/**
 * Copyright (C) JoyStream - All Rights Reserved
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential
 * Written by Bedeho Mender <bedeho.mender@gmail.com>, March 10 2016
 */

#include <protocol_statemachine/Observing.hpp>
#include <protocol_statemachine/Buying.hpp>
#include <protocol_statemachine/Selling.hpp>

#include <iostream>

namespace joystream {
namespace protocol_statemachine {

    Observing::Observing() {
        std::cout << "Entering Observing state." << std::endl;
    }

    sc::result Observing::react(const event::BuyModeStarted & e) {

        std::cout << "Reacting to BuyModeStarted." << std::endl;

        // Client to buy mode
        context<CBStateMachine>().clientToBuyMode(e.terms());

        // Transition to Buy state
        return transit<Buying>();
    }

    sc::result Observing::react(const event::SellModeStarted & e) {

        std::cout << "Reacting to SellModeStarted." << std::endl;

        // Client to Selling mode
        context<CBStateMachine>().clientToSellMode(e.terms(), 0);

        // Transition to Selling state
        return transit<Selling>();
    }

}
}
