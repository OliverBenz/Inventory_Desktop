#include "cMain.hpp"

wxBEGIN_EVENT_TABLE(cMain, wxFrame)
	EVT_TEXT(TXT_SEARCH_ID, cMain::OnFilterUpdate)
	EVT_BUTTON(BTN_SEARCH_ID, cMain::OnFilterUpdate)
	EVT_BUTTON(BTN_NEW_ID, cMain::OnToolbarNew)
	EVT_BUTTON(BTN_CLEAR_ID, cMain::OnToolbarClicked)
wxEND_EVENT_TABLE()

cMain::cMain() : wxFrame(nullptr, wxID_ANY, "Home", wxPoint(50,50), wxSize(800, 600)){
	database = new dbHelper();

	// Create Font
	wxFont font(10, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false);

	// Create Toolbar
	toolBar = this->CreateToolBar(wxTB_HORIZONTAL, wxID_ANY);
	
	wxButton* bNew = new wxButton(toolBar, BTN_NEW_ID, "New", wxDefaultPosition, wxSize(35, 25), 0);
	toolBar->AddControl(bNew);
	
	wxButton* bClear = new wxButton(toolBar, BTN_CLEAR_ID, "Clear", wxDefaultPosition, wxSize(35, 25), 0);
	toolBar->AddControl(bClear);

	toolBar->Realize();

	// Create Search Field
	searchField = new wxTextCtrl(this, TXT_SEARCH_ID, "", wxPoint(10, 10), wxSize(300, 30));
	searchField->SetFont(font);
	searchField->SetHint("Search Inventory");
	
	// Create Search Button
	wxButton* searchButton = new wxButton(this, BTN_SEARCH_ID, "Search", wxPoint(320, 10), wxSize(50, 30), 0);

	// Create Inventory List
	//inventoryList = new wxListBox(this, 10002, wxPoint(10, 50), wxSize(300, 300));
	//inventoryList->SetFont(font);

	items = database->getLocations();

	// Create Grid
	grid = new wxGrid(this, wxID_ANY, wxPoint(10, 50), wxSize(300, 300));
	grid->CreateGrid(2, items.size());
	grid->SetColLabelValue(0, "ID");
	grid->SetColLabelValue(1, "Name");
	grid->HideRowLabels();
	
	// Test fill grid
	if (items.size() > 0) {
		for (size_t i = 0; i < 2; i++) {
			grid->SetReadOnly(i, 0);

			grid->SetCellValue(i, 0, std::to_string(i));
			grid->SetCellValue(i, 1, items[i]);
		}
	}
}

cMain::~cMain() {
}

void cMain::OnFilterUpdate(wxCommandEvent& evt) {
	switch (evt.GetId()) {
		case TXT_SEARCH_ID:
			break;
		case BTN_SEARCH_ID:
			wxMessageBox("Search Button clicked");
			break;
	}
	evt.Skip();
}

void cMain::OnToolbarClicked(wxCommandEvent& evt) {
	switch (evt.GetId()) {
		case BTN_CLEAR_ID:
			searchField->Clear();
			break;
	}
	evt.Skip();
}

void cMain::OnToolbarNew(wxCommandEvent& evt) {
	AddWindow* addWin = new AddWindow(this->GetSize(), this->GetPosition());
	addWin->Show();

	evt.Skip();
}