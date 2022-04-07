(defconst porth-mode-syntax-table
  (with-syntax-table (copy-syntax-table)
    ;; C/C++ style comments
	(modify-syntax-entry ?/ ". 124b")
	(modify-syntax-entry ?* ". 23")
	(modify-syntax-entry ?\n "> b")
    ;; Chars are the same as strings
    (modify-syntax-entry ?' "\"")
    (syntax-table))
  "Syntax table for `porth-mode'.")

(eval-and-compile
  (defconst porth-keywords
    '("if" "else" "while" "do" "include" "memory" "proc"
      "const" "end" "offset" "reset" "assert" "in" "inline"
      "here" "addr-of" "call-like" "let" "peek")))

(defconst porth-highlights
  `((,(regexp-opt porth-keywords 'symbols) . font-lock-keyword-face)))

;;;###autoload
(define-derived-mode porth-mode prog-mode "porth"
  "Major Mode for editing Porth source code."
  :syntax-table porth-mode-syntax-table
  (setq font-lock-defaults '(porth-highlights))
  (setq-local comment-start "// "))

;;;###autoload
(add-to-list 'auto-mode-alist '("\\.porth\\'" . porth-mode))

(provide 'porth-mode)


