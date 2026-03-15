{
  description = "Jazz² Resurrection – open-source Jazz Jackrabbit 2 reimplementation";

  inputs = {
    nixpkgs.url = "https://flakehub.com/f/DeterminateSystems/nixpkgs-weekly/*.tar.gz";
  };

  outputs = inputs @ {
    flake-parts,
    self,
    ...
  }:
    flake-parts.lib.mkFlake {inherit inputs;} {
      systems = ["x86_64-linux" "aarch64-linux"];
      perSystem = {
        pkgs,
        lib,
        system,
        ...
      }: let
        jazz2 = pkgs.stdenv.mkDerivation {
          pname = "jazz2";
          version = "dev";

          src = lib.cleanSource self;

          nativeBuildInputs = [pkgs.cmake];
          buildInputs = with pkgs; [
            curl
            libGL
            libopenmpt
            libvorbis
            openal
            SDL2
            zlib
          ];

          cmakeFlags = [
            (lib.cmakeBool "NCINE_DOWNLOAD_DEPENDENCIES" false)
            (lib.cmakeFeature "NCINE_PREFERRED_BACKEND" "SDL2")
            (lib.cmakeFeature "LIBOPENMPT_INCLUDE_DIR" "${lib.getDev pkgs.libopenmpt}/include/libopenmpt")
          ];

          meta = {
            description = "Open-source Jazz Jackrabbit 2 reimplementation";
            homepage = "https://github.com/deathkiller/jazz2-native";
            license = lib.licenses.gpl3Only;
            mainProgram = "jazz2";
            platforms = lib.platforms.linux;
          };
        };
      in {
        packages.default = jazz2;

        devShells.default = pkgs.mkShell {
          inputsFrom = [jazz2];
          packages = with pkgs; [
            nixfmt
            just
          ];
        };
      };
    };
}
