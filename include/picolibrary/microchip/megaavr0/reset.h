/**
 * picolibrary-microchip-megaavr0
 *
 * Copyright 2021-2022, Andrew Countryman <apcountryman@gmail.com> and the
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
 * \brief picolibrary::Microchip::megaAVR0::Reset interface.
 */

#ifndef PICOLIBRARY_MICROCHIP_MEGAAVR0_RESET_H
#define PICOLIBRARY_MICROCHIP_MEGAAVR0_RESET_H

#include <cstdint>

#include "picolibrary/error.h"
#include "picolibrary/microchip/megaavr0/peripheral.h"
#include "picolibrary/microchip/megaavr0/peripheral/rstctrl.h"
#include "picolibrary/postcondition.h"

/**
 * \brief Microchip megaAVR 0-series reset facilities.
 */
namespace picolibrary::Microchip::megaAVR0::Reset {

/**
 * \brief Reset source(s).
 */
class Source {
  public:
    /**
     * \brief Constructor.
     */
    constexpr Source() noexcept = default;

    /**
     * \brief Constructor.
     *
     * \param[in] rstctrl_rstfr The RSTCTRL peripheral RSTFR register value.
     */
    constexpr Source( std::uint8_t rstctrl_rstfr ) noexcept :
        m_rstctrl_rstfr{ rstctrl_rstfr }
    {
    }

    /**
     * \brief Constructor.
     *
     * \param[in] source The source of the move.
     */
    constexpr Source( Source && source ) noexcept = default;

    /**
     * \brief Constructor.
     *
     * \param[in] original The original to copy.
     */
    constexpr Source( Source const & original ) noexcept = default;

    /**
     * \brief Destructor.
     */
    ~Source() noexcept = default;

    /**
     * \brief Assignment operator.
     *
     * \param[in] expression The expression to be assigned.
     *
     * \return The assigned to object.
     */
    constexpr auto operator=( Source && expression ) noexcept -> Source & = default;

    /**
     * \brief Assignment operator.
     *
     * \param[in] expression The expression to be assigned.
     *
     * \return The assigned to object.
     */
    constexpr auto operator=( Source const & expression ) noexcept -> Source & = default;

    /**
     * \brief Check if a power-on reset occurred.
     *
     * \return true if a power-on reset occur.
     * \return false if a power-on reset did not occur.
     */
    constexpr auto is_power_on_reset() const noexcept -> bool
    {
        return m_rstctrl_rstfr & Peripheral::RSTCTRL::RSTFR::Mask::PORF;
    }

    /**
     * \brief Check if a brown-out reset occurred.
     *
     * \return true if a brown-out reset did occur.
     * \return false if a brown-out reset did not occur.
     */
    constexpr auto is_brown_out_reset() const noexcept -> bool
    {
        return m_rstctrl_rstfr & Peripheral::RSTCTRL::RSTFR::Mask::BORF;
    }

    /**
     * \brief Check if an external reset occurred.
     *
     * \return true if an external reset did occur.
     * \return false if an external reset did not occur.
     */
    constexpr auto is_external_reset() const noexcept -> bool
    {
        return m_rstctrl_rstfr & Peripheral::RSTCTRL::RSTFR::Mask::EXTRF;
    }

    /**
     * \brief Check if a watchdog reset occurred.
     *
     * \return true if a watchdog reset did occur.
     * \return false if a watchdog reset did not occur.
     */
    constexpr auto is_watchdog_reset() const noexcept -> bool
    {
        return m_rstctrl_rstfr & Peripheral::RSTCTRL::RSTFR::Mask::WDRF;
    }

    /**
     * \brief Check if a software reset occurred.
     *
     * \return true if a software reset did occur.
     * \return false if a software reset did not occur.
     */
    constexpr auto is_software_reset() const noexcept -> bool
    {
        return m_rstctrl_rstfr & Peripheral::RSTCTRL::RSTFR::Mask::SWRF;
    }

    /**
     * \brief Check if a UPDI reset occurred.
     *
     * \return true if a UPDI reset did occur.
     * \return false if a UPDI reset did not occur.
     */
    constexpr auto is_updi_reset() const noexcept -> bool
    {
        return m_rstctrl_rstfr & Peripheral::RSTCTRL::RSTFR::Mask::UPDIRF;
    }

  private:
    /**
     * \brief The RSTCTRL peripheral RSTFR register value.
     */
    std::uint8_t m_rstctrl_rstfr{ 0x00 };
};

/**
 * \brief Get the reset source(s).
 *
 * \return The reset source(s).
 */
inline auto source() noexcept -> Source
{
    return Source{ Peripheral::RSTCTRL0::instance().rstfr };
}

/**
 * \brief Clear the reset source(s).
 */
inline void clear_reset_source() noexcept
{
    Peripheral::RSTCTRL0::instance().rstfr = Peripheral::RSTCTRL::RSTFR::Mask::UPDIRF
                                             | Peripheral::RSTCTRL::RSTFR::Mask::SWRF
                                             | Peripheral::RSTCTRL::RSTFR::Mask::WDRF
                                             | Peripheral::RSTCTRL::RSTFR::Mask::EXTRF
                                             | Peripheral::RSTCTRL::RSTFR::Mask::BORF
                                             | Peripheral::RSTCTRL::RSTFR::Mask::PORF;
}

/**
 * \brief Initiate a software reset.
 *
 * \post a software reset is initiated
 */
[[noreturn]] inline void initiate_software_reset() noexcept
{
    Peripheral::RSTCTRL0::instance().swrr = Peripheral::RSTCTRL::SWRR::Mask::SWRE;

    ensure( Generic_Error::RUNTIME_ERROR );
}

} // namespace picolibrary::Microchip::megaAVR0::Reset

#endif // PICOLIBRARY_MICROCHIP_MEGAAVR0_RESET_H
