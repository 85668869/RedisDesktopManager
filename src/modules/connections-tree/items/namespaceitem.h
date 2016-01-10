#pragma once
#include "treeitem.h"
#include "connections-tree/operations.h"

namespace ConnectionsTree {

class NamespaceItem : public TreeItem
{
public:
    NamespaceItem(const QString& fullPath,  QSharedPointer<Operations> operations, QWeakPointer<TreeItem> parent);

    QString getDisplayName() const override;

    QString getName() const;

    QString getIconUrl() const override;

    QString getType() const override { return "namespace"; }

    QList<QSharedPointer<TreeItem>> getAllChilds() const override;

    uint childCount(bool recursive = false) const override;

    QSharedPointer<TreeItem> child(uint row) const override;

    QWeakPointer<TreeItem> parent() const override;

    bool isLocked() const override;

    bool isEnabled() const override;

    void append(QSharedPointer<TreeItem> item);

    QSharedPointer<NamespaceItem> findChildNamespace(const QString& name);

private:
    QString m_fullPath;
    QString m_displayName;
    QSharedPointer<Operations> m_operations;
    QWeakPointer<TreeItem> m_parent;
    bool m_locked;
    QList<QSharedPointer<TreeItem>> m_childItems;
    QHash<QString, QSharedPointer<NamespaceItem>> m_childNamespaces;
};
}
