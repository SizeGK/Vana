/*
Copyright (C) 2008-2015 Vana Development Team

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; version 2
of the License.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/
#pragma once

#include "ConfigFile.hpp"
#include "Ip.hpp"
#include "Types.hpp"
#include <string>

struct InterServerConfig {
	InterServerConfig() :
		loginIp{0}
	{
	}

	bool clientEncryption = true;
	bool clientPing = true;
	bool serverPing = true;
	port_t loginPort = 0;
	Ip loginIp;
};

template <>
struct LuaSerialize<InterServerConfig> {
	auto read(LuaEnvironment &config, const string_t &prefix) -> InterServerConfig {
		InterServerConfig ret;
		ret.clientEncryption = config.get<bool>("use_client_encryption");
		ret.clientPing = config.get<bool>("use_client_ping");
		ret.serverPing = config.get<bool>("use_inter_ping");
		ret.loginIp = Ip{Ip::stringToIpv4(config.get<string_t>("login_ip"))};
		ret.loginPort = config.get<port_t>("login_inter_port");
		return ret;
	}
};