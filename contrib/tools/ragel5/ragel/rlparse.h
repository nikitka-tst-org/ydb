/* Automatically generated by Kelbt from "rlparse.kh".
 *
 * Parts of this file are copied from Kelbt source covered by the GNU
 * GPL. As a special exception, you may use the parts of this file copied
 * from Kelbt source without restriction. The remainder is derived from
 * "rlparse.kh" and inherits the copyright status of that file.
 */

#line 1 "rlparse.kh"
/*
 *  Copyright 2001-2007 Adrian Thurston <thurston@cs.queensu.ca>
 */

/*  This file is part of Ragel.
 *
 *  Ragel is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 * 
 *  Ragel is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 * 
 *  You should have received a copy of the GNU General Public License
 *  along with Ragel; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA 
 */

#ifndef RLPARSE_H
#define RLPARSE_H

#include <iostream>
#include "avltree.h"
#include "parsedata.h"

struct Parser
{
#line 93 "rlparse.kh"


	#line 44 "rlparse.h"
	struct Parser_LangEl *freshEl;
	int freshPos;
	struct Parser_LangEl *pool;
	int numRetry;
	int numNodes;
	struct Parser_LangEl *stackTop;
	struct Parser_LangEl *lastFinal;
	int errCount;
	int curs;
#line 96 "rlparse.kh"

	void init();
	int parseLangEl( int type, const Token *token );

	Parser(const char *fileName, char *sectionName, InputLoc &sectionLoc )
		: sectionName(sectionName)
	{
		pd = new ParseData( fileName, sectionName, sectionLoc );
		exportContext.append( false );
	}

	int token( InputLoc &loc, int tokId, char *tokstart, int toklen );
	void tryMachineDef( InputLoc &loc, char *name, 
		JoinOrLm *joinOrLm, bool isInstance );

	/* Report an error encountered by the parser. */
	ostream &parse_error( int tokId, Token &token );

	ParseData *pd;

	/* The name of the root section, this does not change during an include. */
	char *sectionName;

	NameRef nameRef;
	NameRefList nameRefList;

	Vector<bool> exportContext;
};

#line 84 "rlparse.h"
#define KW_Machine 128
#define KW_Include 129
#define KW_Import 130
#define KW_Write 131
#define TK_Word 132
#define TK_Literal 133
#define TK_Number 134
#define TK_Inline 135
#define TK_Reference 136
#define TK_ColonEquals 137
#define TK_EndSection 138
#define TK_UInt 139
#define TK_Hex 140
#define TK_BaseClause 141
#define TK_DotDot 142
#define TK_ColonGt 143
#define TK_ColonGtGt 144
#define TK_LtColon 145
#define TK_Arrow 146
#define TK_DoubleArrow 147
#define TK_StarStar 148
#define TK_NameSep 149
#define TK_BarStar 150
#define TK_DashDash 151
#define TK_StartCond 152
#define TK_AllCond 153
#define TK_LeavingCond 154
#define TK_Middle 155
#define TK_StartGblError 156
#define TK_AllGblError 157
#define TK_FinalGblError 158
#define TK_NotFinalGblError 159
#define TK_NotStartGblError 160
#define TK_MiddleGblError 161
#define TK_StartLocalError 162
#define TK_AllLocalError 163
#define TK_FinalLocalError 164
#define TK_NotFinalLocalError 165
#define TK_NotStartLocalError 166
#define TK_MiddleLocalError 167
#define TK_StartEOF 168
#define TK_AllEOF 169
#define TK_FinalEOF 170
#define TK_NotFinalEOF 171
#define TK_NotStartEOF 172
#define TK_MiddleEOF 173
#define TK_StartToState 174
#define TK_AllToState 175
#define TK_FinalToState 176
#define TK_NotFinalToState 177
#define TK_NotStartToState 178
#define TK_MiddleToState 179
#define TK_StartFromState 180
#define TK_AllFromState 181
#define TK_FinalFromState 182
#define TK_NotFinalFromState 183
#define TK_NotStartFromState 184
#define TK_MiddleFromState 185
#define RE_Slash 186
#define RE_SqOpen 187
#define RE_SqOpenNeg 188
#define RE_SqClose 189
#define RE_Dot 190
#define RE_Star 191
#define RE_Dash 192
#define RE_Char 193
#define IL_WhiteSpace 194
#define IL_Comment 195
#define IL_Literal 196
#define IL_Symbol 197
#define KW_Action 198
#define KW_AlphType 199
#define KW_Range 200
#define KW_GetKey 201
#define KW_When 202
#define KW_Eof 203
#define KW_Err 204
#define KW_Lerr 205
#define KW_To 206
#define KW_From 207
#define KW_Export 208
#define KW_Break 209
#define KW_Exec 210
#define KW_Hold 211
#define KW_PChar 212
#define KW_Char 213
#define KW_Goto 214
#define KW_Call 215
#define KW_Ret 216
#define KW_CurState 217
#define KW_TargState 218
#define KW_Entry 219
#define KW_Next 220
#define KW_Variable 221
#define KW_Access 222
#define TK_Semi 223
#define _eof 224

#line 126 "rlparse.kh"

#endif
