;;; stm-mode.el --- Stm code editing commands for Emacs

;;; Code:

(defvar stm-mode-hook nil)
(defvar stm-mode-map
  (let ((stm-mode-map (make-keymap)))
    (define-key stm-mode-map "\C-j" 'newline-and-indent)
    stm-mode-map)
  "Keymap for STM major mode")

(add-to-list 'auto-mode-alist '("\\.statemachine\\'" . stm-mode))

(defconst stm-font-lock-keywords-1
  (list
	 '("\\<\\(CALC\\|PRINT\\|SET\\|TIMEOUT\\|SETSTATE\\|SETITEM\\|SETFRAME\\|SETPATTERN\\|SETCPPATTERN\\|ROBOTSPEED\\|LOAD\\|EXEC\\|ADD\\|MUL\\|DIV\\|SUBT\\)\\>" . font-lock-builtin-face))
  "Minimal highlighting expressions for STM mode.")

(defconst stm-font-lock-keywords-2
  (append stm-font-lock-keywords-1
		  (list
			 '("\\<\\(TEST\\|ENDTEST\\|ELSE\\|ELSETEST\\|OR\\|State\\|AND\\|END\\)\\>" . font-lock-keyword-face)
		   '("\\<\\(Value\\|Timeout\\|Const\\|Output\\|Input\\|Path\\|Item\\|Frame\\|Pattern\\|CPPattern\\|Link\\|linkValue\\|Table\\)\\>" . font-lock-constant-face)
			 '("\\<\-*\\([0-9]+\\)\\>" . font-lock-constant-face)))
  "Additional Keywords to highlight in STM mode.")

(defconst stm-font-lock-keywords-3
  (append stm-font-lock-keywords-2
		  (list
			 '("\\<\\(ST_[A-Z0-9_]+\\|UNKNOWN\\)\\>" . font-lock-variable-name-face)
		   '("\\<\\(STATEMACHINEVERSION\\|Delaystop\\|Name\\|Include\\|INLINE\\)\\>" . font-lock-type-face)))
  "Balls-out highlighting in STM mode.")

(defvar stm-font-lock-keywords stm-font-lock-keywords-3
  "Default highlighting expressions for STM mode.")
 

(defun stm-indent-line ()
  "Indent current line as STM code."
  (interactive)
  (beginning-of-line)
  (if (bobp)
			(indent-line-to 0)		   ; First line is always non-indented
		(let ((not-indented t) (cur-indent 0) (keyw 0))
			(cond
			 (
				(looking-at "^[ \t]*\\(END\\|ENDTEST\\|ELSE\\)") ; If the line we are looking at is the end of a block, then decrease the indentation
				(progn
					(setq keyw 1)
					(save-excursion
						(forward-line -1)
						(setq cur-indent (- (current-indentation) default-tab-width)))
					(if (< cur-indent 0) ; We can't indent past the left margin
							(setq cur-indent 0)
						)
					)
				)
			 (
				(looking-at "^[ \t]*\\(State\\|AND\\|OR\\|STATEMACHINEVERSION\\|Name\\|Delaystop\\|Include\\)") ; //No indentation
				(progn
					(setq keyw 1)
					(save-excursion
						(forward-line -1)
						(setq cur-indent (current-indentation))
						)
					)
				)
			 (
				(save-excursion
					(forward-line -1)
					(if (looking-at "^[ \t]*\\(State\\|TEST\\|AND\\|OR\\|ELSE\\)")
							(setq cur-indent (+ (current-indentation) default-tab-width))
						(setq cur-indent (current-indentation))
						)
					)
				)
			 )
			(if cur-indent
					(indent-line-to cur-indent)
				(indent-line-to 0)
				)
			)
		)
	)
	
(defvar stm-mode-syntax-table
  (let ((stm-mode-syntax-table (make-syntax-table)))
	
    ; This is added so entity names with underscores can be more easily parsed
	(modify-syntax-entry ?_ "w" stm-mode-syntax-table)
	
	; Comment styles are same as C++
	(modify-syntax-entry ?\; "< b" stm-mode-syntax-table)
	(modify-syntax-entry ?\n "> b" stm-mode-syntax-table)
	stm-mode-syntax-table)
  "Syntax table for stm-mode")
  
(defun stm-mode ()
  (interactive)
  (kill-all-local-variables)
  (use-local-map stm-mode-map)
  (set-syntax-table stm-mode-syntax-table)
  ;; Set up font-lock
  (set (make-local-variable 'font-lock-defaults) '(stm-font-lock-keywords))
  ;; Register our indentation function
  (set (make-local-variable 'indent-line-function) 'stm-indent-line)  
  (setq major-mode 'stm-mode)
  (setq mode-name "STM")
  (run-hooks 'stm-mode-hook))

(provide 'stm-mode)

;;; stm-mode.el ends here
