output_file_name = output
source_file = main.cpp

output: main.cpp
	@powershell -Command "Write-Host -ForegroundColor Red "Vytvaram subor: ""
	g++.exe -o $(output_file_name) $(source_file)
	@powershell -Command "Write-Host -ForegroundColor DarkGreen "Spustam subor: $(output_file_name).exe"" 
	@.\$(output_file_name).exe

clean:
	del $(output_file_name).exe

