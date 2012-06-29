pdf:
	@clear
	@pdflatex -shell-escape monografia.tex # compila c/ sumário vazio e sem links p/ referências
	@bibtex monografia # compila as referências
	@makeindex monografia.nlo -s nomencl.ist -o monografia.nls # gera a lista de siglas
	@pdflatex -shell-escape monografia.tex # compila adicionando o sumário
	@pdflatex -shell-escape monografia.tex # compila adicionando os links p/ as referências
	@evince monografia.pdf &

clean:
	@rm *.bbl *.aux *.blg *.log *.toc *.lof *.lol *.out *.pdf *.ilg *.nlo *.nls 2> /dev/null; exit 0
