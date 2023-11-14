{
  "targets": [
    {
      "target_name": "mi_modulo",
      "sources": [ "mi_modulo.cc" ],
      "cflags!": [ "-fno-exceptions" ],
      "cflags_cc!": [ "-fno-exceptions" ],
      "include_dirs": [
        "<!@(node -p \"require('nan')\")"
      ]
    }
  ]
}
