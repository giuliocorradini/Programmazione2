# diff

Esempio d'uso del comando `diff`.

```sh
diff -ru new old > old2new.patch
```

L'opzione `-r` considera i file ricorsivamente mentre l'opzione `-u` produce
il risultato del diff in formato _unified_.

## Esempio di output

```diff
diff -ru old/Makefile new/Makefile
--- old/Makefile	2022-05-23 14:44:34.000000000 +0200
+++ new/Makefile	2022-05-23 14:47:27.000000000 +0200
@@ -7,6 +7,9 @@
 $(EXEC): $(OBJ)
 	$(CXX) -o $(EXEC) $(OBJ)
 
+grafo.o:
+	g++ -o grafo.o grafo.cc
+
 .PHONY: clean cleanall depends
 clean:
 	rm -f *.o
Only in old: grafo.cc
diff -ru old/main.cc new/main.cc
--- old/main.cc	2022-05-23 14:44:34.000000000 +0200
+++ new/main.cc	2022-05-23 14:46:56.000000000 +0200
@@ -49,7 +49,7 @@
 
     ifstream in(filename);
 
-    graph g = g_build(in, isOriented, isWeighted);
+    graph g = g_build(in, !isOriented, !isWeighted);
 
     for(int i=1; i<=get_dim(g); i++) {
         cout << i << " - ";
@@ -59,8 +59,6 @@
 
             a = get_nextadj(a);
         }
-
-        cout << endl;
     }
 
     in.close();
Only in new: new.cc

```

Se lancio il comando così non vengono considerati eventuali file che ho cancellato
o creato.

## Tutte le modifiche

Per tenere traccia anche dei file cancellati o creati posso invocare diff con l'opzione
`-N` e l'output generato includerà tutti i file creati o cancellati (interamente).

```sh
diff -N -ru old new > old2new.patch
```