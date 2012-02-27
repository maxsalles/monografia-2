pdf:
	@clear
	@pdflatex monografia.tex # compila c/ sumário vazio e sem links p/ referências
	@bibtex monografia # compila as referências
	@pdflatex monografia.tex # compila adicionando o sumário
	@pdflatex monografia.tex # compila adicionando os links p/ as referências
	@evince monografia.pdf &

clean:
	@rm *.bbl *.aux *.blg *.log *.toc *.lof *.lol *.out *.pdf 2> /dev/null; exit 0

