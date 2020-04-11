#pragma once

#include <wx/wx.h>
#include <wx/grid.h>

#include <vector>
#include <string>

#include "lib/dbHelper.hpp"
#include "lib/Item.hpp"
#include "AddWindow.hpp"

// Define IDs
#define TXT_SEARCH_ID 10001

#define BTN_NEW_ID 10010
#define BTN_CLEAR_ID 10011
#define BTN_SEARCH_ID 10012
#define BTN_REFRESH_ID 10013

class cMain: public wxFrame {
	dbHelper* database = nullptr;

	wxToolBar* toolBar = nullptr;
	wxTextCtrl* searchField = nullptr;
	wxListBox* inventoryList = nullptr;
	wxGrid* grid = nullptr;

	std::vector<Item> items;

public: 
	cMain();
	~cMain();

	void fillGrid();

	void OnFilterUpdate(wxCommandEvent& evt);
	void OnToolbarClicked(wxCommandEvent& evt);
	void OnToolbarNew(wxCommandEvent& evt);
	void OnToolbarRefresh(wxCommandEvent& evt);

	wxDECLARE_EVENT_TABLE();
};

