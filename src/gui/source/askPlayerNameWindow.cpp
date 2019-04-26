#include "./../include/askPlayerNameWindow.h"

namespace Labyrinth_44422 {
	namespace gui {

		AskPlayerName::AskPlayerName(QWidget * parent) : QInputDialog{parent} {
			this->setCancelButtonText("Plus de joueurs");
			this->setInputMode(QInputDialog::InputMode::TextInput);
			this->setLabelText("Entrez un nom pour ce joueur.");
			this->setWindowTitle("Entrez un nom pour ce joueur.");
			this->setOkButtonText("Ok");
			this->setModal(true);
			this->activateWindow();
			this->show();
		}

	} // namespace gui
} // namespace Labyrinth_44422
