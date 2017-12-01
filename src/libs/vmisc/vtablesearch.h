/***************************************************************************
 *                                                                         *
 *   Copyright (C) 2017  Seamly, LLC                                       *
 *                                                                         *
 *   https://github.com/fashionfreedom/seamly2d                             *
 *                                                                         *
 ***************************************************************************
 **
 **  Seamly2D is free software: you can redistribute it and/or modify
 **  it under the terms of the GNU General Public License as published by
 **  the Free Software Foundation, either version 3 of the License, or
 **  (at your option) any later version.
 **
 **  Seamly2D is distributed in the hope that it will be useful,
 **  but WITHOUT ANY WARRANTY; without even the implied warranty of
 **  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 **  GNU General Public License for more details.
 **
 **  You should have received a copy of the GNU General Public License
 **  along with Seamly2D.  If not, see <http://www.gnu.org/licenses/>.
 **
 **************************************************************************

 ************************************************************************
 **
 **  @file   vtablesearch.h
 **  @author Roman Telezhynskyi <dismine(at)gmail.com>
 **  @date   15 9, 2015
 **
 **  @brief
 **  @copyright
 **  This source code is part of the Valentine project, a pattern making
 **  program, whose allow create and modeling patterns of clothing.
 **  Copyright (C) 2015 Valentina project
 **  <https://github.com/fashionfreedom/seamly2d> All Rights Reserved.
 **
 **  Valentina is free software: you can redistribute it and/or modify
 **  it under the terms of the GNU General Public License as published by
 **  the Free Software Foundation, either version 3 of the License, or
 **  (at your option) any later version.
 **
 **  Valentina is distributed in the hope that it will be useful,
 **  but WITHOUT ANY WARRANTY; without even the implied warranty of
 **  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 **  GNU General Public License for more details.
 **
 **  You should have received a copy of the GNU General Public License
 **  along with Valentina.  If not, see <http://www.gnu.org/licenses/>.
 **
 *************************************************************************/

#ifndef VTABLESEARCH_H
#define VTABLESEARCH_H

#include <QObject>
#include <QList>
#include <QString>
#include <QTableWidget>
#include <QtGlobal>

class VTableSearch: public QObject
{
    Q_OBJECT
public:
    explicit VTableSearch(QTableWidget *table, QObject *parent = nullptr);

    void Find(const QString &term);
    void FindPrevious();
    void FindNext();
    void RemoveRow(int row);
    void AddRow(int row);
    void RefreshList(const QString &term);

signals:
    void HasResult(bool state);

private:
    Q_DISABLE_COPY(VTableSearch)

    QTableWidget *table;
    int           searchIndex;
    QList<QTableWidgetItem *> searchList;

    void Clear();
    void ShowNext(int newIndex);
};

#endif // VTABLESEARCH_H
