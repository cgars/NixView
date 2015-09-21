#include "MainViewWidget.hpp"
#include "ui_MainViewWidget.h"
#include "RawTreeView.hpp"
#include "AnotherTree.hpp"


/**
* @brief Container for all widgets for data display.
* @param nix_file_path: path to opened nix file
*/
MainViewWidget::MainViewWidget(std::string& nix_file_path, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainViewWidget)
{
    ui->setupUi(this);

    nix_file = nix::File::open(nix_file_path, nix::FileMode::ReadOnly);

    populate_data_stacked_widget();
    connect_widgets();
}

void MainViewWidget::populate_data_stacked_widget()
{
    rtv = new RawTreeView(nix_file);
    ui->data_stacked_Widget->addWidget(rtv);

    AnotherTree* aot  = new AnotherTree();
    ui->data_stacked_Widget->addWidget(aot);
}

void MainViewWidget::data_combo_box_changed(int index) {
    ui->data_stacked_Widget->setCurrentIndex(index);
}

void MainViewWidget::set_test_label(QTreeWidgetItem* qt, int c)
{
    ui->test_label->setText(qt->text(0));
}

void MainViewWidget::connect_widgets()
{
    QObject::connect(ui->data_combo_box, SIGNAL(currentIndexChanged(int)), this, SLOT(data_combo_box_changed(int)));

    QObject::connect(rtv->get_tree_widget(), SIGNAL(itemDoubleClicked(QTreeWidgetItem*, int)), this, SLOT(set_test_label(QTreeWidgetItem* ,int)));
}

MainViewWidget::~MainViewWidget()
{
    delete ui;
}
