#include "TelephoneForm.h"

void Telephone::TelephoneForm::Telephone_Form_Closing(System::Object ^sender, System::Windows::Forms::FormClosingEventArgs ^e)
{
	oleDbDataAdapter1->Update(dataSet1->Tables["Table1"]);
}

void Telephone::TelephoneForm::Telephone_Load(System::Object ^sender, System::EventArgs ^e)
{
	oleDbDataAdapter1->Fill(dataTable1);
}

void Telephone::TelephoneForm::button_Search_Click(System::Object^  sender, System::EventArgs^  e) {
	for (int i = 0; i < dataGridView1->RowCount - 1; i++) {
		dataGridView1->Rows[i]->Selected = false; //Выделение синим
		for (int j = 0; j < dataGridView1->ColumnCount - 1; j++) {
			if (dataGridView1->Rows[i]->Cells[j]->Value != NULL && dataGridView1->Rows[i]->Cells[j]->Value->ToString() == textBox7->Text) {
				dataGridView1->Rows[i]->Selected = true;
				dataGridView1->CurrentCell = dataGridView1[0, i];
				//dataGridView1->Rows[i]->DefaultCellStyle->BackColor = Color::Red;
				break;
			}
		}
	}
}

void Telephone::TelephoneForm::button_Change_Click(System::Object^ sender, System::EventArgs^ e) {
	Person <String> person;

	for (int i = 0; i < dataGridView1->RowCount - 1; i++) {
		dataGridView1->Rows[i]->Selected = false; //Выделение синим
		for (int j = 0; j < dataGridView1->ColumnCount - 1; j++) {
			if (dataGridView1->Rows[i]->Cells[j]->Value != NULL && dataGridView1->Rows[i]->Cells[j]->Value->ToString() == textBox9->Text) {
				dataGridView1->Rows[i]->Selected = true; //Выделение синим
				dataGridView1->CurrentCell = dataGridView1[0, i];
				bindingSource1->RemoveCurrent();
				break;
			}
		}
	}

	oleDbDataAdapter1->Update(dataSet1->Tables["Table1"]);

	person.number = textBox9->Text;
	person.name = textBox10->Text;
	person.surname = textBox11->Text;
	person.secondname = textBox12->Text;
	person.passport = textBox13->Text;
	person.adres = textBox14->Text;

	System::Data::OleDb::OleDbConnection^ aConn = gcnew System::Data::OleDb::OleDbConnection(L"Provider=Microsoft.Jet.OLEDB.4.0;Data Source=C:\\Users\\Андрей\\source\\repos\\Telephone\\Database1.mdb");
	aConn->Open();
	System::Data::OleDb::OleDbCommand^ bComm = gcnew System::Data::OleDb::OleDbCommand();
	bComm->Connection = aConn;
	bComm->CommandText = "INSERT INTO `Table1` (`Number`, `Name`, `Surname`, `Patronymic`, `Passport`, `Adress`) VALUES ('" + person.number + "', '" + person.name + "', '" + person.surname + "', '" + person.secondname + "', '" + person.passport + "', '" + person.adres + "' )";
	bComm->ExecuteNonQuery();
	aConn->Close();

	dataSet1->Tables["Table1"]->Clear();
	oleDbDataAdapter1->Fill(dataSet1, "Table1");
	bindingSource1->ResetBindings(false);
	oleDbDataAdapter1->Update(dataSet1->Tables["Table1"]);
}

void Telephone::TelephoneForm::button_Delete_Click(System::Object^  sender, System::EventArgs^  e) {
	//bComm->CommandText = "DELETE FROM `Table1` WHERE Number = " + del;

	for (int i = 0; i < dataGridView1->RowCount - 1; i++) {
		dataGridView1->Rows[i]->Selected = false; //Выделение синим
		for (int j = 0; j < dataGridView1->ColumnCount - 1; j++) {
			if (dataGridView1->Rows[i]->Cells[j]->Value != NULL && dataGridView1->Rows[i]->Cells[j]->Value->ToString() == textBox8->Text) {
				dataGridView1->Rows[i]->Selected = true; //Выделение синим
				dataGridView1->CurrentCell = dataGridView1[0, i];
				bindingSource1->RemoveCurrent();
				break;
			}
		}
	}
	oleDbDataAdapter1->Update(dataSet1->Tables["Table1"]);
}

void Telephone::TelephoneForm::button_Add_Click(System::Object^  sender, System::EventArgs^  e) {
	Person <String> person;

	//int text1;
	//text1 = Convert::ToInt32(textBox1->Text);
	//person.number = text1;

	person.number = textBox1->Text;
	person.name = textBox2->Text;
	person.surname = textBox3->Text;
	person.secondname = textBox4->Text;
	person.passport = textBox5->Text;
	person.adres = textBox6->Text;

	System::Data::OleDb::OleDbConnection^ aConn = gcnew System::Data::OleDb::OleDbConnection(L"Provider=Microsoft.Jet.OLEDB.4.0;Data Source=C:\\Users\\Андрей\\source\\repos\\Telephone\\Database1.mdb");
	aConn->Open();
	System::Data::OleDb::OleDbCommand^ bComm = gcnew System::Data::OleDb::OleDbCommand();
	bComm->Connection = aConn;
	bComm->CommandText = "INSERT INTO `Table1` (`Number`, `Name`, `Surname`, `Patronymic`, `Passport`, `Adress`) VALUES ('" + person.number + "', '" + person.name + "', '" + person.surname + "', '" + person.secondname + "', '" + person.passport + "', '" + person.adres + "' )";
	bComm->ExecuteNonQuery();
	aConn->Close();

	dataSet1->Tables["Table1"]->Clear();
	oleDbDataAdapter1->Fill(dataSet1, "Table1");
	bindingSource1->ResetBindings(false);
	oleDbDataAdapter1->Update(dataSet1->Tables["Table1"]);
}

void Telephone::TelephoneForm::button_Update_Click(System::Object^ sender, System::EventArgs^ e) {
	dataSet1->Tables["Table1"]->Clear();
	oleDbDataAdapter1->Fill(dataSet1, "Table1");
	bindingSource1->ResetBindings(false);
	oleDbDataAdapter1->Update(dataSet1->Tables["Table1"]);
}