/*
JuffEd - An advanced text editor
Copyright 2007-2010 Mikhail Murzin

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License 
version 2 as published by the Free Software Foundation.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
*/

#ifndef __JUFFED_DOC_HANDLER_INT_H__
#define __JUFFED_DOC_HANDLER_INT_H__

#include "LibConfig.h"

#include "Enums.h"

namespace Juff {

class Document;
class Project;

class LIBJUFF_EXPORT DocHandlerInt {
public:
	/**
	* Returns app's main window.
	*/
	virtual QWidget* mainWindow() const = 0;
	
	/**
	* Returns current document. If there is no documents then returns a NullDoc.
	*/
	virtual Juff::Document* curDoc() const = 0;

	/**
	* Returns document by file name. If there is no such document opened then returns a NullDoc.
	*/
	virtual Juff::Document* getDoc(const QString&) const = 0;

	/**
	* Returns current project.
	*/
	virtual Juff::Project* curPrj() const = 0;

	/**
	* Opens a document with a given file name or activates it if it is already opened.
	*/
	virtual void openDoc(const QString&, Juff::PanelIndex panel = Juff::PanelCurrent, bool addToRecent = false) = 0;

	/**
	* Closes the document with a given file name.
	*/
	virtual void closeDoc(const QString&) = 0;

	/**
	* Closes all document at the given panel.
	*/
	virtual bool closeAllDocs(Juff::PanelIndex panel) = 0;
	
	/**
	* Closes all document except for the given index at the given panel.
	*/
	virtual void closeAllOtherDocs(int index, Juff::PanelIndex panel) = 0;
	
	/**
	* Saves the document with a given file name.
	*/
	virtual void saveDoc(const QString&) = 0;

	/**
	* Returns the number of currently opened documents for the given panel.
	*/
	virtual int docCount(Juff::PanelIndex) const = 0;

	/**
	* Returns the list of currently opened documents.
	*/
	virtual QStringList docList() const = 0;
};

}

#endif // __JUFFED_DOC_HANDLER_INT_H__
