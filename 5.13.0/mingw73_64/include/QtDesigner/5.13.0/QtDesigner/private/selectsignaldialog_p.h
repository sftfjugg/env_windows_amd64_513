/****************************************************************************
**
** Copyright (C) 2017 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the Qt Designer of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:GPL-EXCEPT$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3 as published by the Free Software
** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT
** included in the packaging of this file. Please review the following
** information to ensure the GNU General Public License requirements will
** be met: https://www.gnu.org/licenses/gpl-3.0.html.
**
** $QT_END_LICENSE$
**
****************************************************************************/

//
//  W A R N I N G
//  -------------
//
// This file is not part of the Qt API.  It exists for the convenience
// of Qt Designer.  This header
// file may change from version to version without notice, or even be removed.
//
// We mean it.
//

#ifndef SELECTSIGNALDIALOG_H
#define SELECTSIGNALDIALOG_H

#include <QtWidgets/qdialog.h>
#include <QtCore/qstringlist.h>

QT_BEGIN_NAMESPACE

class QDesignerFormEditorInterface;
class QStandardItemModel;

namespace Ui { class SelectSignalDialog; }

namespace qdesigner_internal {

class SelectSignalDialog : public QDialog
{
    Q_OBJECT
public:
    struct Method
    {
        Method() {}
        explicit Method(const QString &c, const QString &s, const QStringList &p = QStringList())
            : className(c), signature(s), parameterNames(p) {}
        bool isValid() const { return !signature.isEmpty(); }

        QString className;
        QString signature;
        QStringList parameterNames;
    };

    explicit SelectSignalDialog(QWidget *parent = nullptr);
    ~SelectSignalDialog();

    Method selectedMethod() const;

    void populate(QDesignerFormEditorInterface *core, QObject *object,
                  const QString &defaultSignal);

private slots:
    void currentChanged(const QModelIndex &, const QModelIndex &);
    void activated(const QModelIndex &);

private:
    Method methodFromIndex(const QModelIndex &) const;
    void populateModel(QDesignerFormEditorInterface *core, QObject *object);

    Ui::SelectSignalDialog *m_ui;
    QPushButton *m_okButton;
    QStandardItemModel *m_model;
};

} // namespace qdesigner_internal

QT_END_NAMESPACE

Q_DECLARE_METATYPE(qdesigner_internal::SelectSignalDialog::Method)

#endif // SELECTSIGNALDIALOG_H
