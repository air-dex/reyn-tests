/// @file patterngetargs.hpp
/// @brief Header of PatternGetArgs
/// @author Romain Ducher
///
/// @section LICENSE
///
/// Copyright 2013 Romain Ducher
///
/// This file is part of LibRT.
///
/// LibRT is free software: you can redistribute it and/or modify it under
/// the terms of the GNU Lesser General Public License as published by
/// the Free Software Foundation, either version 3 of the License, or
/// (at your option) any later version.
///
/// LibRT is distributed in the hope that it will be useful, but WITHOUT
/// ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
/// FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License
/// for more details.
///
/// You should have received a copy of the GNU Lesser General Public License
/// along with LibRT. If not, see <http://www.gnu.org/licenses/>.

#ifndef PATTERNGETARGS_HPP
#define PATTERNGETARGS_HPP

#include "../../base/communicators/getargs.hpp"

namespace LibRT {
	namespace Pebkac {

		/// @class PatternGetArgs
		/// @brief GetArgs for filling a pattern.
		///
		/// It fills a pattern with GET arguments and then this pattern is
		/// appended to the base URL.
		class PatternGetArgs : public GetArgs
		{
			public:
				/// @fn PatternGetArgs(QString getParams = ArgsMap(),
				///					   QString getPattern = "");
				/// @brief Constructor
				/// @param getParams GET parameters.
				/// @param getPattern Pattern to fill.
				PatternGetArgs(ArgsMap getParams = ArgsMap(),
							   QString getPattern = "");

				/// @fn virtual QString getBuiltArgs();
				/// @brief Building the HTTP args with the elements of the struct.
				/// @return Args of the struct built with the build(ArgsMap); method.
				virtual QString getBuiltArgs();

			protected:
				/// @brief Pattern to fill.
				/// Elements which have to be replaces are called <code>%1</code>,
				/// <code>%2</code>, ... ,<code>%n</code>. They are sorted in
				/// lexical order and are replaced by their real value in the
				/// { @link PatternGetArgs::getBuiltArgs() } method.
				QString pattern;
		};
	}
}

#endif // PATTERNGETARGS_HPP
