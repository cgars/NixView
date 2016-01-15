#ifndef NIXDATAMODEL_H
#define NIXDATAMODEL_H

#include <QStandardItemModel>
#include <nix.hpp>

typedef QList<QStandardItem*> Row;
typedef QList<QString> RowStrings;

class NixDataModel : public QStandardItemModel
{
public:
    NixDataModel(nix::File);

private:
    nix::File nix_file;
    QStandardItem* root_node;
    QList<QStandardItem*> create_entry_row(QList<QString>);
    QString s_to_q(std::string);
    template<typename T>
    std::string get_created_at(T);
    template<typename T>
    std::string get_updated_at(T);
    void nix_file_to_model();

    template<typename T>
    void add_content(QStandardItem*, T nix_entity);

    void add_subsec_prop(QStandardItem*, nix::Section);

    template<typename T>
    RowStrings create_rowstrings(T arg, std::string storagetype, std::string root_child_link, std::string nixtype="", std::string shape="");

    template<typename T>
    void add_linked_sources(QStandardItem* item, T nix_entity);

    template<typename T>
    void add_linked_metadata(QStandardItem* item, T nix_entity);
};

#endif // NIXDATAMODEL_H