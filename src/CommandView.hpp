/*
 * Copyright (C) 2023-2024 Dāniels Ponamarjovs <bonux@duck.com>
 *
 * This file is part of tMus.
 *
 * tMus is free software: you can redistribute it and/or
 * modify it under the terms of the GNU General Public
 * License as published by the Free Software Foundation, either
 * version 3 of the License, or (at your option) any later version.
 *
 * tMus is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with tMus. If not, see <https://www.gnu.org/licenses/>.
 */

#pragma once

#include "CommandProcessor.hpp"

#include <memory>
#include <ncpp/NotCurses.hh>

class CommandView : public ncpp::Widget
{
public:
    CommandView(ncpp::Plane&);

    void draw();
    void search(std::string str);
    bool handle_input(const ncinput&) noexcept;

    void init(CommandProcessor* proc) noexcept;

private:

    void ProcessCommand(std::string);
    void CompleteNext() noexcept;
    void ReportError(std::string_view error) noexcept;

    void clearDraw() noexcept;
    void clearCommand() noexcept;

    void disableCursor();
    void enableCursor(int y = -1, int x = -1);
    void toggleCursor();

    [[nodiscard]] std::string u32vecToString(const std::vector<std::uint32_t>&) const noexcept;

    ncpp::Plane m_ncp;
    CommandProcessor* m_cmdProc{};

    std::vector<std::uint32_t> m_commandBuffer;

    std::uint64_t m_textColor{};
    std::uint64_t m_backgroundColor{};

    unsigned m_dimy{};
    unsigned m_dimx{};

    bool m_focus{};
    bool m_search{};
    bool m_CursorEnabled{};
};
