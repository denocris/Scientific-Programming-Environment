target = deal2lkit_softwarex
ASP_FILE=$(target).tex

all: compile

compile: restart
	pdflatex $(target)
	bibtex   $(target)
	pdflatex $(target)
	pdflatex $(target)

restart:
	rm -f $(target).pdf *.bbl *.log *.lot *.toc *.out *.blg *.aux

clean:
	rm -f *.bbl *.log *.lot *.toc *.out *.blg *.aux *.lof *.lol *.spl *.cb *.cb2 *.fls *.fdb_latexmk *.synctex.gz

open:
	qpdfview --unique --quiet $(target).pdf &

qpdfview: compile open clean

aspell:
	aspell -d en_US -lt -c $(ASP_FILE)
