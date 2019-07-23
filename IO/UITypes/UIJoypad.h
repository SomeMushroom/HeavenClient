//////////////////////////////////////////////////////////////////////////////
// This file is part of the Journey MMORPG client                           //
// Copyright © 2015-2016 Daniel Allendorf                                   //
//                                                                          //
// This program is free software: you can redistribute it and/or modify     //
// it under the terms of the GNU Affero General Public License as           //
// published by the Free Software Foundation, either version 3 of the       //
// License, or (at your option) any later version.                          //
//                                                                          //
// This program is distributed in the hope that it will be useful,          //
// but WITHOUT ANY WARRANTY; without even the implied warranty of           //
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the            //
// GNU Affero General Public License for more details.                      //
//                                                                          //
// You should have received a copy of the GNU Affero General Public License //
// along with this program.  If not, see <http://www.gnu.org/licenses/>.    //
//////////////////////////////////////////////////////////////////////////////
#pragma once
#include "../UIDragElement.h"

#include "../Template/BoolPair.h"
#include "../Components/Textfield.h"

namespace jrc
{
	class UIJoypad : public UIDragElement<PosJOYPAD>
	{
	public:
		static constexpr Type TYPE = UIElement::Type::JOYPAD;
		static constexpr bool FOCUSED = false;
		static constexpr bool TOGGLED = true;

		UIJoypad();

		void draw(float inter) const override;
		void update() override;

		void send_key(int32_t keycode, bool pressed) override;

	protected:
		Button::State button_pressed(uint16_t buttonid) override;

	private:
		void cancel();
		void save();

		enum Buttons : uint16_t
		{
			DEFAULT,
			CANCEL,
			OK
		};

		bool alternative_settings;
		BoolPair<Texture> backgrnd;

		enum Setting : uint8_t
		{
			// Joypad name
			NAME,

			// Keys
			ATTACK,
			JUMP,
			PICKUP,

			// Hot keys
			HOTKEY0,
			HOTKEY1,
			HOTKEY2,
			HOTKEY3,
			HOTKEY4,
			HOTKEY5,
			HOTKEY6,
			HOTKEY7,
			SETTING_NUM
		};

		Text key_text[SETTING_NUM];
	};
}