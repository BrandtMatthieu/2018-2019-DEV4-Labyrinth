#include <QDialogButtonBox>
#include <QPushButton>
#include <QTextEdit>
#include <QVBoxLayout>

#include "./../include/rulesWindow.h"

namespace Labyrinth_44422 {
	namespace gui {

		/**
		 * Creates a window with the rules of the game
		 * @param parent the parent window
		 */
		RulesWindow::RulesWindow(QWidget *parent) : QDialog{parent} {

			this->setMinimumSize(QSize(480, 360));

			auto *textBox = new QTextEdit(this);
			textBox->setPlainText(this->rules);
			textBox->setReadOnly(true);

			auto *okButton = new QPushButton("Jouer !");
			okButton->setDefault(true);

			auto *buttonBox = new QDialogButtonBox(Qt::Horizontal);
			buttonBox->addButton(okButton, QDialogButtonBox::AcceptRole);

			connect(buttonBox, SIGNAL(accepted()), this, SLOT(accept()));

			auto *layout = new QVBoxLayout;
			layout->addWidget(textBox);
			layout->addWidget(buttonBox);

			setLayout(layout);

			this->update();
			this->show();
			this->isActiveWindow();
		}

	} // namespace gui
} // namespace Labyrinth_44422
