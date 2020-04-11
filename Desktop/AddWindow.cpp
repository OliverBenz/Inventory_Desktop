#include <vector>
#include "AddWindow.hpp"
#include "lib/Category.hpp"
#include "lib/Item.hpp"

wxBEGIN_EVENT_TABLE(AddWindow, wxFrame)
	EVT_BUTTON(BTN_CONFIRM_ID, AddWindow::OnConfirmPressed)
wxEND_EVENT_TABLE()

AddWindow::AddWindow(wxSize parentSize, wxPoint parentPos) : wxFrame(nullptr, wxID_ANY, "Add new Item", wxPoint(parentPos.x + parentSize.x + 5, parentPos.y), wxSize(200, parentSize.y)) {
	database = new dbHelper();
	txtName = new wxTextCtrl(this, wxID_ANY, "", wxPoint(10, 10), wxSize(100, 30));
	txtName->SetHint(wxString("Item Name.."));

	btnConfirm = new wxButton(this, BTN_CONFIRM_ID, "Add to Inventory", wxPoint(10, 50), wxSize(100, 30), 0);
}

AddWindow::~AddWindow(){

}

void AddWindow::OnConfirmPressed(wxCommandEvent& evt) {
	std::string name = std::string(txtName->GetValue().mb_str());
	if(name.length() > 0)
		database->pushItem(Item(0, name, "VGA Test", 1, 1));
}