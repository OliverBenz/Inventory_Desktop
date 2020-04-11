#pragma once

#include <wx/wx.h>
#include "lib/Item.hpp"
#include "lib/dbHelper.hpp"

#define BTN_CONFIRM_ID 20010

class AddWindow : public wxFrame {
	dbHelper* database = nullptr;
	wxTextCtrl* txtName = nullptr;
	wxButton* btnConfirm = nullptr;

	wxDECLARE_EVENT_TABLE();

public:
	AddWindow(wxSize parentSize, wxPoint parentPos);
	~AddWindow();

	void OnConfirmPressed(wxCommandEvent& evt);
};