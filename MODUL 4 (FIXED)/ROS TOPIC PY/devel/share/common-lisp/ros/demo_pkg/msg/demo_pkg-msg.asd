
(cl:in-package :asdf)

(defsystem "demo_pkg-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "Pesan" :depends-on ("_package_Pesan"))
    (:file "_package_Pesan" :depends-on ("_package"))
  ))