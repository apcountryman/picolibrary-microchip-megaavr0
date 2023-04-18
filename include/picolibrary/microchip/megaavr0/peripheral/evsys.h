/**
 * picolibrary-microchip-megaavr0
 *
 * Copyright 2021-2023, Andrew Countryman <apcountryman@gmail.com> and the
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
 * \brief picolibrary::Microchip::megaAVR0::Peripheral::EVSYS interface.
 */

#ifndef PICOLIBRARY_MICROCHIP_MEGAAVR0_PERIPHERAL_EVSYS_H
#define PICOLIBRARY_MICROCHIP_MEGAAVR0_PERIPHERAL_EVSYS_H

#include <cstdint>

#include "picolibrary/bit_manipulation.h"
#include "picolibrary/microchip/megaavr0/register.h"

namespace picolibrary::Microchip::megaAVR0::Peripheral {

/**
 * \brief Microchip megaAVR 0-series Event System (EVSYS) peripheral.
 */
class EVSYS {
  public:
    /**
     * \brief Channel Strobe (STROBE) register.
     *
     * This register has the following fields:
     * - Channel 0 Strobe (CHANNEL0)
     * - Channel 1 Strobe (CHANNEL1)
     * - Channel 2 Strobe (CHANNEL2)
     * - Channel 3 Strobe (CHANNEL3)
     * - Channel 4 Strobe (CHANNEL4)
     * - Channel 5 Strobe (CHANNEL5)
     * - Channel 6 Strobe (CHANNEL6)
     * - Channel 7 Strobe (CHANNEL7)
     */
    class STROBE : public Register<std::uint8_t> {
      public:
        /**
         * \brief Field sizes.
         */
        struct Size {
            static constexpr auto CHANNEL0 = std::uint_fast8_t{ 1 }; ///< CHANNEL0.
            static constexpr auto CHANNEL1 = std::uint_fast8_t{ 1 }; ///< CHANNEL1.
            static constexpr auto CHANNEL2 = std::uint_fast8_t{ 1 }; ///< CHANNEL2.
            static constexpr auto CHANNEL3 = std::uint_fast8_t{ 1 }; ///< CHANNEL3.
            static constexpr auto CHANNEL4 = std::uint_fast8_t{ 1 }; ///< CHANNEL4.
            static constexpr auto CHANNEL5 = std::uint_fast8_t{ 1 }; ///< CHANNEL5.
            static constexpr auto CHANNEL6 = std::uint_fast8_t{ 1 }; ///< CHANNEL6.
            static constexpr auto CHANNEL7 = std::uint_fast8_t{ 1 }; ///< CHANNEL7.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto CHANNEL0 = std::uint_fast8_t{}; ///< CHANNEL0.
            static constexpr auto CHANNEL1 = std::uint_fast8_t{ CHANNEL0 + Size::CHANNEL0 }; ///< CHANNEL1.
            static constexpr auto CHANNEL2 = std::uint_fast8_t{ CHANNEL1 + Size::CHANNEL1 }; ///< CHANNEL2.
            static constexpr auto CHANNEL3 = std::uint_fast8_t{ CHANNEL2 + Size::CHANNEL2 }; ///< CHANNEL3.
            static constexpr auto CHANNEL4 = std::uint_fast8_t{ CHANNEL3 + Size::CHANNEL3 }; ///< CHANNEL4.
            static constexpr auto CHANNEL5 = std::uint_fast8_t{ CHANNEL4 + Size::CHANNEL4 }; ///< CHANNEL5.
            static constexpr auto CHANNEL6 = std::uint_fast8_t{ CHANNEL5 + Size::CHANNEL5 }; ///< CHANNEL6.
            static constexpr auto CHANNEL7 = std::uint_fast8_t{ CHANNEL6 + Size::CHANNEL6 }; ///< CHANNEL7.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto CHANNEL0 = mask<std::uint8_t>( Size::CHANNEL0, Bit::CHANNEL0 ); ///< CHANNEL0.
            static constexpr auto CHANNEL1 = mask<std::uint8_t>( Size::CHANNEL1, Bit::CHANNEL1 ); ///< CHANNEL1.
            static constexpr auto CHANNEL2 = mask<std::uint8_t>( Size::CHANNEL2, Bit::CHANNEL2 ); ///< CHANNEL2.
            static constexpr auto CHANNEL3 = mask<std::uint8_t>( Size::CHANNEL3, Bit::CHANNEL3 ); ///< CHANNEL3.
            static constexpr auto CHANNEL4 = mask<std::uint8_t>( Size::CHANNEL4, Bit::CHANNEL4 ); ///< CHANNEL4.
            static constexpr auto CHANNEL5 = mask<std::uint8_t>( Size::CHANNEL5, Bit::CHANNEL5 ); ///< CHANNEL5.
            static constexpr auto CHANNEL6 = mask<std::uint8_t>( Size::CHANNEL6, Bit::CHANNEL6 ); ///< CHANNEL6.
            static constexpr auto CHANNEL7 = mask<std::uint8_t>( Size::CHANNEL7, Bit::CHANNEL7 ); ///< CHANNEL7.
        };

        STROBE() = delete;

        STROBE( STROBE && ) = delete;

        STROBE( STROBE const & ) = delete;

        ~STROBE() = delete;

        auto operator=( STROBE && ) = delete;

        auto operator=( STROBE const & ) = delete;

        using Register<std::uint8_t>::operator=;
    };

    /**
     * \brief Channel Generator Selection (CHANNEL) register.
     *
     * This register has the following fields:
     * - Channel Generator Selection (GENERATOR)
     */
    class CHANNEL : public Register<std::uint8_t> {
      public:
        /**
         * \brief Field sizes.
         */
        struct Size {
            static constexpr auto GENERATOR = std::uint_fast8_t{ 8 }; ///< GENERATOR.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto GENERATOR = std::uint_fast8_t{}; ///< GENERATOR.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto GENERATOR = mask<std::uint8_t>( Size::GENERATOR, Bit::GENERATOR ); ///< GENERATOR.
        };

        /**
         * \brief GENERATOR.
         */
        enum GENERATOR : std::uint8_t {
            GENERATOR_NONE = 0x00 << Bit::GENERATOR, ///< None.

            GENERATOR_UPDI = 0x01 << Bit::GENERATOR, ///< UPDI.

            GENERATOR_RTC_OVF  = 0x06 << Bit::GENERATOR, ///< RTC OVF.
            GENERATOR_RTC_CMP  = 0x07 << Bit::GENERATOR, ///< RTC CMP.
            GENERATOR_RTC_PIT0 = 0x08 << Bit::GENERATOR, ///< RTC PIT0.
            GENERATOR_RTC_PIT1 = 0x09 << Bit::GENERATOR, ///< RTC PIT1.
            GENERATOR_RTC_PIT2 = 0x0A << Bit::GENERATOR, ///< RTC PIT2.
            GENERATOR_RTC_PIT3 = 0x0B << Bit::GENERATOR, ///< RTC PIT3.

            GENERATOR_CCL_LUT0 = 0x10 << Bit::GENERATOR, ///< CCL LUT0.
            GENERATOR_CCL_LUT1 = 0x11 << Bit::GENERATOR, ///< CCL LUT1.
            GENERATOR_CCL_LUT2 = 0x12 << Bit::GENERATOR, ///< CCL LUT2.
            GENERATOR_CCL_LUT3 = 0x13 << Bit::GENERATOR, ///< CCL LUT3.

            GENERATOR_AC0_OUT = 0x20 << Bit::GENERATOR, ///< AC0 OUT.

            GENERATOR_ADC0_RESRDY = 0x24 << Bit::GENERATOR, ///< ADC0 RESRDY.

            GENERATOR_PORT0_PIN0 = 0x40 << Bit::GENERATOR, ///< PORT0 PIN0.
            GENERATOR_PORT0_PIN1 = 0x41 << Bit::GENERATOR, ///< PORT0 PIN1.
            GENERATOR_PORT0_PIN2 = 0x42 << Bit::GENERATOR, ///< PORT0 PIN2.
            GENERATOR_PORT0_PIN3 = 0x43 << Bit::GENERATOR, ///< PORT0 PIN3.
            GENERATOR_PORT0_PIN4 = 0x44 << Bit::GENERATOR, ///< PORT0 PIN4.
            GENERATOR_PORT0_PIN5 = 0x45 << Bit::GENERATOR, ///< PORT0 PIN5.
            GENERATOR_PORT0_PIN6 = 0x46 << Bit::GENERATOR, ///< PORT0 PIN6.
            GENERATOR_PORT0_PIN7 = 0x47 << Bit::GENERATOR, ///< PORT0 PIN7.

            GENERATOR_PORT1_PIN0 = 0x48 << Bit::GENERATOR, ///< PORT1 PIN0.
            GENERATOR_PORT1_PIN1 = 0x49 << Bit::GENERATOR, ///< PORT1 PIN1.
            GENERATOR_PORT1_PIN2 = 0x4A << Bit::GENERATOR, ///< PORT1 PIN2.
            GENERATOR_PORT1_PIN3 = 0x4B << Bit::GENERATOR, ///< PORT1 PIN3.
            GENERATOR_PORT1_PIN4 = 0x4C << Bit::GENERATOR, ///< PORT1 PIN4.
            GENERATOR_PORT1_PIN5 = 0x4D << Bit::GENERATOR, ///< PORT1 PIN5.
            GENERATOR_PORT1_PIN6 = 0x4E << Bit::GENERATOR, ///< PORT1 PIN6.
            GENERATOR_PORT1_PIN7 = 0x4F << Bit::GENERATOR, ///< PORT1 PIN7.

            GENERATOR_USART0_XCK = 0x60 << Bit::GENERATOR, ///< USART0 XCK.
            GENERATOR_USART1_XCK = 0x61 << Bit::GENERATOR, ///< USART1 XCK.
            GENERATOR_USART2_XCK = 0x62 << Bit::GENERATOR, ///< USART2 XCK.
            GENERATOR_USART3_XCK = 0x63 << Bit::GENERATOR, ///< USART3 XCK.

            GENERATOR_SPI0_SCK = 0x68 << Bit::GENERATOR, ///< SPI0 SCK.

            GENERATOR_TCA0_OVF_LUNF = 0x80 << Bit::GENERATOR, ///< TCA0 OVF/LUNF.
            GENERATOR_TCA0_HUNF     = 0x81 << Bit::GENERATOR, ///< TCA0 HUNF.
            GENERATOR_TCA0_CMP0     = 0x84 << Bit::GENERATOR, ///< TCA0 CMP0.
            GENERATOR_TCA0_CMP1     = 0x85 << Bit::GENERATOR, ///< TCA0 CMP1.
            GENERATOR_TCA0_CMP2     = 0x86 << Bit::GENERATOR, ///< TCA0 CMP2.

            GENERATOR_TCB0_CAPT = 0xA0 << Bit::GENERATOR, ///< TCB0 CAPT.
            GENERATOR_TCB1_CAPT = 0xA2 << Bit::GENERATOR, ///< TCB1 CAPT.
            GENERATOR_TCB2_CAPT = 0xA4 << Bit::GENERATOR, ///< TCB2 CAPT.
            GENERATOR_TCB3_CAPT = 0xA6 << Bit::GENERATOR, ///< TCB3 CAPT.
        };

        CHANNEL() = delete;

        CHANNEL( CHANNEL && ) = delete;

        CHANNEL( CHANNEL const & ) = delete;

        ~CHANNEL() = delete;

        auto operator=( CHANNEL && ) = delete;

        auto operator=( CHANNEL const & ) = delete;

        using Register<std::uint8_t>::operator=;
    };

    /**
     * \brief User Channel Mux (USER) register.
     *
     * This register has the following fields:
     * - User Channel Selection (CHANNEL)
     */
    class USER : public Register<std::uint8_t> {
      public:
        /**
         * \brief Field sizes.
         */
        struct Size {
            static constexpr auto CHANNEL = std::uint_fast8_t{ 8 }; ///< CHANNEL.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto CHANNEL = std::uint_fast8_t{}; ///< CHANNEL.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto CHANNEL = mask<std::uint8_t>( Size::CHANNEL, Bit::CHANNEL ); ///< CHANNEL.
        };

        /**
         * \brief CHANNEL.
         */
        enum CHANNEL : std::uint8_t {
            CHANNEL_NONE = 0 << Bit::CHANNEL, ///< No channel is connected to this Event System user.
            CHANNEL_CHANNEL0 = 1 << Bit::CHANNEL, ///< Event user is connected to CHANNEL0.
            CHANNEL_CHANNEL1 = 2 << Bit::CHANNEL, ///< Event user is connected to CHANNEL1.
            CHANNEL_CHANNEL2 = 3 << Bit::CHANNEL, ///< Event user is connected to CHANNEL2.
            CHANNEL_CHANNEL3 = 4 << Bit::CHANNEL, ///< Event user is connected to CHANNEL3.
            CHANNEL_CHANNEL4 = 5 << Bit::CHANNEL, ///< Event user is connected to CHANNEL4.
            CHANNEL_CHANNEL5 = 6 << Bit::CHANNEL, ///< Event user is connected to CHANNEL5.
            CHANNEL_CHANNEL6 = 7 << Bit::CHANNEL, ///< Event user is connected to CHANNEL6.
            CHANNEL_CHANNEL7 = 8 << Bit::CHANNEL, ///< Event user is connected to CHANNEL7.
        };

        USER() = delete;

        USER( USER && ) = delete;

        USER( USER const & ) = delete;

        ~USER() = delete;

        auto operator=( USER && ) = delete;

        auto operator=( USER const & ) = delete;

        using Register<std::uint8_t>::operator=;
    };

    /**
     * \brief CHANNEL register array index.
     */
    enum CHANNEL_Index : std::uint_fast8_t {
        CHANNEL_0 = 0, ///< Channel 0.
        CHANNEL_1 = 1, ///< Channel 1.
        CHANNEL_2 = 2, ///< Channel 2.
        CHANNEL_3 = 3, ///< Channel 3.
        CHANNEL_4 = 4, ///< Channel 4.
        CHANNEL_5 = 5, ///< Channel 5.
        CHANNEL_6 = 6, ///< Channel 6.
        CHANNEL_7 = 7, ///< Channel 7.
    };

    /**
     * \brief USER register array index.
     */
    enum USER_Index : std::uint8_t {
        USER_CCLLUT0A = 0,  ///< CCL LUT0 event input A.
        USER_CCLLUT0B = 1,  ///< CCL LUT0 event input B.
        USER_CCLLUT1A = 2,  ///< CCL LUT1 event input A.
        USER_CCLLUT1B = 3,  ///< CCL LUT1 event input B.
        USER_CCLLUT2A = 4,  ///< CCL LUT2 event input A.
        USER_CCLLUT2B = 5,  ///< CCL LUT2 event input B.
        USER_CCLLUT3A = 6,  ///< CCL LUT3 event input A.
        USER_CCLLUT3B = 7,  ///< CCL LUT3 event input B.
        USER_ADC0     = 8,  ///< ADC0 Trigger.
        USER_EVOUTA   = 9,  ///< EVSYS pin output A.
        USER_EVOUTB   = 10, ///< EVSYS pin output B.
        USER_EVOUTC   = 11, ///< EVSYS pin output C.
        USER_EVOUTD   = 12, ///< EVSYS pin output D.
        USER_EVOUTE   = 13, ///< EVSYS pin output E.
        USER_EVOUTF   = 14, ///< EVSYS pin output F.
        USER_USART0   = 15, ///< USART0 event input.
        USER_USART1   = 16, ///< USART0 event input.
        USER_USART2   = 17, ///< USART0 event input.
        USER_USART3   = 18, ///< USART0 event input.
        USER_TCA0     = 19, ///< TCA0 event input.
        USER_TCB0     = 20, ///< TCB0 event input.
        USER_TCB1     = 21, ///< TCB1 event input.
        USER_TCB2     = 22, ///< TCB2 event input.
        USER_TCB3     = 23, ///< TCB3 event input.
    };

    /**
     * \brief STROBE.
     */
    STROBE strobe;

    /**
     * \brief Reserved registers (offset 0x01-0x0F).
     */
    Reserved_Register<std::uint8_t> const reserved_0x01_0x0F[ ( 0x0F - 0x01 ) + 1 ];

    union {
        /**
         * \brief CHANNEL.
         */
        CHANNEL channel[ 7 + 1 ];

        struct {
            /**
             * \brief Channel 0 (CHANNEL0) register.
             */
            CHANNEL channel0;

            /**
             * \brief Channel 1 (CHANNEL1) register.
             */
            CHANNEL channel1;

            /**
             * \brief Channel 2 (CHANNEL2) register.
             */
            CHANNEL channel2;

            /**
             * \brief Channel 3 (CHANNEL3) register.
             */
            CHANNEL channel3;

            /**
             * \brief Channel 4 (CHANNEL4) register.
             */
            CHANNEL channel4;

            /**
             * \brief Channel 5 (CHANNEL5) register.
             */
            CHANNEL channel5;

            /**
             * \brief Channel 6 (CHANNEL6) register.
             */
            CHANNEL channel6;

            /**
             * \brief Channel 7 (CHANNEL7) register.
             */
            CHANNEL channel7;
        };
    };

    /**
     * \brief Reserved registers (offset 0x18-0x1F).
     */
    Reserved_Register<std::uint8_t> const reserved_0x18_0x1F[ ( 0x1F - 0x18 ) + 1 ];

    union {
        /**
         * \brief USER.
         */
        USER user[ 23 + 1 ];

        struct {
            /**
             * \brief CCL LUT0 Event Input A User (USERCCLLUT0A) register.
             */
            USER userccllut0a;

            /**
             * \brief CCL LUT0 Event Input B User (USERCCLLUT0B) register.
             */
            USER userccllut0b;

            /**
             * \brief CCL LUT1 Event Input A User (USERCCLLUT1A) register.
             */
            USER userccllut1a;

            /**
             * \brief CCL LUT1 Event Input B User (USERCCLLUT1B) register.
             */
            USER userccllut1b;

            /**
             * \brief CCL LUT2 Event Input A User (USERCCLLUT2A) register.
             */
            USER userccllut2a;

            /**
             * \brief CCL LUT2 Event Input B User (USERCCLLUT2B) register.
             */
            USER userccllut2b;

            /**
             * \brief CCL LUT3 Event Input A User (USERCCLLUT3A) register.
             */
            USER userccllut3a;

            /**
             * \brief CCL LUT3 Event Input B User (USERCCLLUT3B) register.
             */
            USER userccllut3b;

            /**
             * \brief ADC0 Trigger User (USERADC0) register.
             */
            USER useradc0;

            /**
             * \brief EVSYS Pin Output A User (USEREVOUTA) register.
             */
            USER userevouta;

            /**
             * \brief EVSYS Pin Output B User (USEREVOUTB) register.
             */
            USER userevoutb;

            /**
             * \brief EVSYS Pin Output C User (USEREVOUTC) register.
             */
            USER userevoutc;

            /**
             * \brief EVSYS Pin Output D User (USEREVOUTD) register.
             */
            USER userevoutd;

            /**
             * \brief EVSYS Pin Output E User (USEREVOUTE) register.
             */
            USER userevoute;

            /**
             * \brief EVSYS Pin Output F User (USEREVOUTF) register.
             */
            USER userevoutf;

            /**
             * \brief USART 0 Event Input User (USERUSART0) register.
             */
            USER userusart0;

            /**
             * \brief USART 1 Event Input User (USERUSART1) register.
             */
            USER userusart1;

            /**
             * \brief USART 2 Event Input User (USERUSART2) register.
             */
            USER userusart2;

            /**
             * \brief USART 3 Event Input User (USERUSART3) register.
             */
            USER userusart3;

            /**
             * \brief TCA0 Event Input User (USERTCA0) register.
             */
            USER usertca0;

            /**
             * \brief TCB0 Event Input User (USERTCB0) register.
             */
            USER usertcb0;

            /**
             * \brief TCB1 Event Input User (USERTCB1) register.
             */
            USER usertcb1;

            /**
             * \brief TCB2 Event Input User (USERTCB2) register.
             */
            USER usertcb2;

            /**
             * \brief TCB3 Event Input User (USERTCB3) register.
             */
            USER usertcb3;
        };
    };

    EVSYS() = delete;

    EVSYS( EVSYS && ) = delete;

    EVSYS( EVSYS const & ) = delete;

    ~EVSYS() = delete;

    auto operator=( EVSYS && ) = delete;

    auto operator=( EVSYS const & ) = delete;
};

} // namespace picolibrary::Microchip::megaAVR0::Peripheral

#endif // PICOLIBRARY_MICROCHIP_MEGAAVR0_PERIPHERAL_EVSYS_H
