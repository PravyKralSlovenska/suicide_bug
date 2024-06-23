output_file_name = output
content_dir = content

output:
	@powershell -Command "Write-Host -ForegroundColor Red "Vytvaram subor: ""
	g++ -I src/include -L src/lib -o $(output_file_name) .\content\main.cpp -l mingw32 -l SDL2main -l SDL2
	@powershell -Command "Write-Host -ForegroundColor DarkGreen "Spustam subor: $(output_file_name).exe"" 
	@.\$(output_file_name).exe

clean:
	@del $(output_file_name).exe

run:
	@.\$(output_file_name).exe
