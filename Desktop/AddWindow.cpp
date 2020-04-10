#include <vector>
#include "AddWindow.hpp"
#include "lib/Category.hpp"

AddWindow::AddWindow(wxSize parentSize, wxPoint parentPos) : wxFrame(nullptr, wxID_ANY, "Add new Item", wxPoint(parentPos.x + parentSize.x + 5, parentPos.y), wxSize(200, parentSize.y)) {
	database = new dbHelper();
	txtName = new wxTextCtrl(this, wxID_ANY, "", wxPoint(10, 10), wxSize(100, 30));
	txtName->SetHint(wxString("Item Name.."));

	btnConfirm = new wxButton(this, wxID_ANY, "Add to Inventory", wxPoint(10, 50), wxSize(100, 30), 0);
}

AddWindow::~AddWindow(){

}
