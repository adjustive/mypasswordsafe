/* $Header: /home/cvsroot/MyPasswordSafe/src/myutil.hpp,v 1.6 2004/11/01 21:34:58 nolan Exp $
 * Copyright 2004, Semantic Gap (TM)
 * http://www.semanticgap.com/
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */
#ifndef MYUTIL_HPP
#define MYUTIL_HPP

#include <string>
#include <vector>
#include <iostream>
#include "config.h"
#include "exception.hpp"

using std::cerr;
using std::endl;
using std::string;
using std::vector;

class QString;
class SafeGroup;
class Safe;

//#define DEBUG 1

#ifdef DEBUG
#define DBGOUT(str) cerr << __FILE__ << "(" << __LINE__ << ")\t" << str << endl
//#define DBGOUT(str) cerr << __func__ << "(" << __LINE__ << "): " << str << endl
//#define DBGOUT(str) cerr << __PRETTY_FUNCTION__ << ": " << str << endl
#else
#define DBGOUT(str)
#endif

void printBinary(std::ostream &str, unsigned char c);
void copyToClipboard(const QString &str);

SafeGroup *findOrCreateGroup(Safe *safe, const QString &group_name);
QString thisGroup(const QString &);
QString parentGroup(const QString &);
SafeGroup *findGroup(SafeGroup *group, const QString &full_group);

QString escapeGroup(const QString &);
QString unescapeGroup(const QString &);

class EscapeException: public Exception
{
public:
  EscapeException();
};

#endif
