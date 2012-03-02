pdf:
	@clear
	@latex monografia.tex # compila c/ sumário vazio e sem links p/ referências
	@bibtex monografia # compila as referências
	@latex monografia.tex # compila adicionando o sumário
	@latex monografia.tex # compila adicionando os links p/ as referências
	@dvips -o monografia.ps monografia.dvi
	@ps2pdf monografia.ps monografia.pdf
	@evince monografia.pdf &

clean:
	@rm *.bbl *.aux *.blg *.log *.toc *.lof *.lol *.out *.pdf 2> /dev/null; exit 0

