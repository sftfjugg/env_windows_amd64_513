/****************************************************************************
**
** Copyright (C) 2017 Klaralvdalens Datakonsult AB (KDAB).
** Contact: http://www.qt-project.org/legal
**
** This file is part of the Qt3D module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL3$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see http://www.qt.io/terms-conditions. For further
** information use the contact form at http://www.qt.io/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 3 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPLv3 included in the
** packaging of this file. Please review the following information to
** ensure the GNU Lesser General Public License version 3 requirements
** will be met: https://www.gnu.org/licenses/lgpl.html.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 2.0 or later as published by the Free
** Software Foundation and appearing in the file LICENSE.GPL included in
** the packaging of this file. Please review the following information to
** ensure the GNU General Public License version 2.0 requirements will be
** met: http://www.gnu.org/licenses/gpl-2.0.html.
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef QT3DANIMATION_ANIMATION_LERPCLIPBLEND_P_H
#define QT3DANIMATION_ANIMATION_LERPCLIPBLEND_P_H

//
//  W A R N I N G
//  -------------
//
// This file is not part of the Qt API.  It exists for the convenience
// of other Qt classes.  This header file may change from version to
// version without notice, or even be removed.
//
// We mean it.
//

#include <Qt3DAnimation/private/clipblendnode_p.h>

QT_BEGIN_NAMESPACE

namespace Qt3DAnimation {

namespace Animation {

class Q_AUTOTEST_EXPORT LerpClipBlend : public ClipBlendNode
{
public:
    LerpClipBlend();
    ~LerpClipBlend();

    inline float blendFactor() const { return m_blendFactor; }
    void setBlendFactor(float blendFactor) { m_blendFactor = blendFactor; } // For unit tests

    inline Qt3DCore::QNodeId startClipId() const { return m_startClipId; }
    void setStartClipId(Qt3DCore::QNodeId startClipId) { m_startClipId = startClipId; }  // For unit tests

    inline Qt3DCore::QNodeId endClipId() const { return m_endClipId; }
    void setEndClipId(Qt3DCore::QNodeId endClipId) { m_endClipId = endClipId; }  // For unit tests

    void sceneChangeEvent(const Qt3DCore::QSceneChangePtr &e) final;

    inline QVector<Qt3DCore::QNodeId> allDependencyIds() const override
    {
        return currentDependencyIds();
    }

    inline QVector<Qt3DCore::QNodeId> currentDependencyIds() const override
    {
        return { m_startClipId, m_endClipId };
    }

    double duration() const override;

protected:
    ClipResults doBlend(const QVector<ClipResults> &blendData) const final;

private:
    void initializeFromPeer(const Qt3DCore::QNodeCreatedChangeBasePtr &change) final;

    Qt3DCore::QNodeId m_startClipId;
    Qt3DCore::QNodeId m_endClipId;
    float m_blendFactor;
};

} // Animation

} // Qt3DAnimation

QT_END_NAMESPACE

#endif // QT3DANIMATION_ANIMATION_LERPCLIPBLEND_P_H
