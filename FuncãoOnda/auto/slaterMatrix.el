(TeX-add-style-hook
 "slaterMatrix"
 (lambda ()
   (TeX-run-style-hooks
    "latex2e"
    "article"
    "art10"
    "amsmath"
    "graphicx")
   (LaTeX-add-labels
    "fig:slaterMatrix"))
 :latex)

