/**
 * picolibrary-microchip-megaavr0
 *
 * Copyright 2021, Andrew Countryman <apcountryman@gmail.com> and the
 * picolibrary-microchip-megaavr0 contributors
 *
 * Licensed under the Apache License, Version 2.0 (the "License"); you may not use this
 * file except in compliance with the License. You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software distributed under
 * the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied. See the License for the specific language governing
 * permissions and limitations under the License.
 */

/**
 * \file
 * \brief picolibrary::Microchip::megaAVR0::Peripheral::PORT interface.
 */

#ifndef PICOLIBRARY_MICROCHIP_MEGAAVR0_PERIPHERAL_PORT_H
#define PICOLIBRARY_MICROCHIP_MEGAAVR0_PERIPHERAL_PORT_H

#include <cstdint>

#include "picolibrary/bit_manipulation.h"
#include "picolibrary/microchip/megaavr0/peripheral/instance.h"
#include "picolibrary/microchip/megaavr0/register.h"

namespace picolibrary::Microchip::megaAVR0::Peripheral {

/**
 * \brief Microchip megaAVR 0-series General Purpose Input/Output (GPIO) Port (PORT)
 *        peripheral.
 */
class PORT {
  public:
    /**
     * \brief Port Control (PORTCTRL) register.
     *
     * This register has the following fields:
     * - Slew Rate Limit Enable (SRL)
     */
    class PORTCTRL : public Register<std::uint8_t> {
      public:
        /**
         * \brief Field Sizes.
         */
        struct Size {
            static constexpr auto SRL      = std::uint_fast8_t{ 1 }; ///< SRL.
            static constexpr auto RESERVED = std::uint_fast8_t{ 7 }; ///< Reserved.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto SRL = std::uint_fast8_t{}; ///< SRL.
            static constexpr auto RESERVED = std::uint_fast8_t{ SRL + Size::SRL }; ///< Reserved.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto SRL = mask<std::uint8_t>( Size::SRL, Bit::SRL ); ///< SRL.
            static constexpr auto RESERVED = mask<std::uint8_t>( Size::RESERVED, Bit::RESERVED ); ///< Reserved.
        };

        PORTCTRL() = delete;

        PORTCTRL( PORTCTRL && ) = delete;

        PORTCTRL( PORTCTRL const & ) = delete;

        ~PORTCTRL() = delete;

        auto operator=( PORTCTRL && ) = delete;

        auto operator=( PORTCTRL const & ) = delete;

        using Register<std::uint8_t>::operator=;
    };

    /**
     * \brief Pin Control (PINCTRL) register.
     *
     * This register has the following fields:
     * - Input/Sense Configuration (ISC)
     * - Pull-Up Enable (PULLUPEN)
     * - Inverted I/O Enable (INVEN)
     */
    class PINCTRL : public Register<std::uint8_t> {
      public:
        /**
         * \brief Field Sizes.
         */
        struct Size {
            static constexpr auto ISC      = std::uint_fast8_t{ 3 }; ///< ISC.
            static constexpr auto PULLUPEN = std::uint_fast8_t{ 1 }; ///< PULLUPEN.
            static constexpr auto RESERVED = std::uint_fast8_t{ 3 }; ///< Reserved.
            static constexpr auto INVEN    = std::uint_fast8_t{ 1 }; ///< INVEN.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto ISC = std::uint_fast8_t{}; ///< ISC.
            static constexpr auto PULLUPEN = std::uint_fast8_t{ ISC + Size::ISC }; ///< PULLUPEN.
            static constexpr auto RESERVED = std::uint_fast8_t{ PULLUPEN + Size::PULLUPEN }; ///< Reserved.
            static constexpr auto INVEN = std::uint_fast8_t{ RESERVED + Size::RESERVED }; ///< INVEN.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto ISC = mask<std::uint8_t>( Size::ISC, Bit::ISC ); ///< ISC.
            static constexpr auto PULLUPEN = mask<std::uint8_t>( Size::PULLUPEN, Bit::PULLUPEN ); ///< PULLUPEN.
            static constexpr auto RESERVED = mask<std::uint8_t>( Size::RESERVED, Bit::RESERVED ); ///< Reserved.
            static constexpr auto INVEN = mask<std::uint8_t>( Size::INVEN, Bit::INVEN ); ///< INVEN.
        };

        PINCTRL() = delete;

        PINCTRL( PINCTRL && ) = delete;

        PINCTRL( PINCTRL const & ) = delete;

        ~PINCTRL() = delete;

        auto operator=( PINCTRL && ) = delete;

        auto operator=( PINCTRL const & ) = delete;

        using Register<std::uint8_t>::operator=;

        /**
         * \brief Enable a pin's internal pull-up resistor.
         */
        void enable_pull_up() noexcept
        {
            *this |= Mask::PULLUPEN;
        }

        /**
         * \brief Disable a pin's internal pull-up resistor.
         */
        void disable_pull_up() noexcept
        {
            *this &= ~Mask::PULLUPEN;
        }
    };

    /**
     * \brief Data Direction (DIR) register.
     */
    Register<std::uint8_t> dir;

    /**
     * \brief Data Direction Set (DIRSET) register.
     */
    Register<std::uint8_t> dirset;

    /**
     * \brief Data Direction Clear (DIRCLR) register.
     */
    Register<std::uint8_t> dirclr;

    /**
     * \brief Data Direction Toggle (DIRTGL) register.
     */
    Register<std::uint8_t> dirtgl;

    /**
     * \brief Output Value (OUT) register.
     */
    Register<std::uint8_t> out;

    /**
     * \brief Output Value Set (OUTSET) register.
     */
    Register<std::uint8_t> outset;

    /**
     * \brief Output Value Clear (OUTCLR) register.
     */
    Register<std::uint8_t> outclr;

    /**
     * \brief Output Value Toggle (OUTTGL) register.
     */
    Register<std::uint8_t> outtgl;

    /**
     * \brief Input Value (IN) register.
     */
    Register<std::uint8_t> in;

    /**
     * \brief Interrupt Flags (INTFLAGS) register.
     */
    Register<std::uint8_t> intflags;

    /**
     * \brief PORTCTRL.
     */
    PORTCTRL portctrl;

    /**
     * \brief Reserved registers.
     */
    Reserved_Register<std::uint8_t> const reserved[ ( 0x0F - 0x0B ) + 1 ];

    /**
     * \brief PINCTRL.
     */
    PINCTRL pinctrl[ ( 0x17 - 0x10 ) + 1 ];

    PORT() = delete;

    PORT( PORT && ) = delete;

    PORT( PORT const & ) = delete;

    ~PORT() = delete;

    auto operator=( PORT && ) = delete;

    auto operator=( PORT const & ) = delete;

    /**
     * \brief Configure a pin to act as an internally pulled-up input pin.
     *
     * \param[in] mask The mask identifying the pin to be configured to act as an
     *            internally pulled-up input.
     */
    void configure_pin_as_internally_pulled_up_input( std::uint8_t mask ) noexcept
    {
        dirclr = mask;
    }

    /**
     * \brief Configure a pin to act as a push-pull I/O pin.
     *
     * \param[in] mask The mask identifying the pin to be configured to act as a push-pull
     *            I/O pin.
     */
    void configure_pin_as_push_pull_io( std::uint8_t mask ) noexcept
    {
        dirset = mask;
    }

    /**
     * \brief Configure a pin to act as an open-drain I/O pin.
     *
     * \param[in] mask The mask identifying the pin to be configured to act as an
     *            open-drain I/O pin.
     */
    void configure_pin_as_open_drain_io( std::uint8_t mask ) noexcept
    {
        outclr = mask;
    }

    /**
     * \brief Enable a pin's internal pull-up resistor.
     *
     * \param[in] n The pin number of the pin whose internal pull-up resistor is to be
     *            enabled.
     */
    void enable_pull_up( std::uint_fast8_t n ) noexcept
    {
        pinctrl[ n ].enable_pull_up();
    }

    /**
     * \brief Disable a pin's internal pull-up resistor.
     *
     * \param[in] n The pin number of the pin whose internal pull-up resistor is to be
     *            disabled.
     */
    void disable_pull_up( std::uint_fast8_t n ) noexcept
    {
        pinctrl[ n ].disable_pull_up();
    }

    /**
     * \brief Get the state of a pin.
     *
     * \input[in] mask The mask identifying the pin whose state is to be gotten.
     *
     * \return The state of the pin.
     */
    auto state( std::uint8_t mask ) const noexcept -> std::uint8_t
    {
        return in & mask;
    }

    /**
     * \brief Transition a push-pull I/O pin to the high state.
     *
     * \param[in] mask The mask identifying the push-pull I/O pin to transition to the
     *            high state.
     */
    void transition_push_pull_io_to_high( std::uint8_t mask ) noexcept
    {
        outset = mask;
    }

    /**
     * \brief Transition an open-drain I/O pin to the high state.
     *
     * \param[in] mask The mask identifying the open-drain I/O pin to transition to the
     *            high state.
     */
    void transition_open_drain_io_to_high( std::uint8_t mask ) noexcept
    {
        dirclr = mask;
    }

    /**
     * \brief Transition a push-pull I/O pin to the low state.
     *
     * \param[in] mask The mask identifying the push-pull I/O pin to transition to the low
     *            state.
     */
    void transition_push_pull_io_to_low( std::uint8_t mask ) noexcept
    {
        outclr = mask;
    }

    /**
     * \brief Transition an open-drain I/O pin to the low state.
     *
     * \param[in] mask The mask identifying the open-drain I/O pin to transition to the
     *            low state.
     */
    void transition_open_drain_io_to_low( std::uint8_t mask ) noexcept
    {
        dirset = mask;
    }

    /**
     * \brief Toggle the state of a push-pull I/O pin.
     *
     * \param[in] mask The mask identifying the push-pull I/O pin to toggle the state of.
     */
    void toggle_push_pull_io( std::uint8_t mask ) noexcept
    {
        outtgl = mask;
    }

    /**
     * \brief Toggle the state of an open-drain I/O pin.
     *
     * \param[in] mask The mask identifying the open-drain I/O pin to toggle the state of.
     */
    void toggle_open_drain_io( std::uint8_t mask ) noexcept
    {
        dirtgl = mask;
    }
};

/**
 * \brief Microchip megaAVR 0-series General Purpose Input/Output (GPIO) Port (PORT)
 *        peripheral instance.
 *
 * \tparam INSTANCE_ADDRESS The address of the PORT instance.
 */
template<std::uintptr_t INSTANCE_ADDRESS>
using PORT_Instance = Instance<PORT, INSTANCE_ADDRESS>;

} // namespace picolibrary::Microchip::megaAVR0::Peripheral

#endif // PICOLIBRARY_MICROCHIP_MEGAAVR0_PERIPHERAL_PORT_H
